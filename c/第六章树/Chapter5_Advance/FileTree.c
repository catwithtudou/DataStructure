#include "FileTree.h"

/** 为文件树结点分配内存空间（结点工厂函数） */
FileNode * FileNodeFactory(){
    FileNode * node = (FileNode *)malloc(sizeof(FileNode));
    node->type = TYPE_FILE;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    node->parent = NULL;
    return node;
}

/**
 * 将文件目录树读入内存（创建文件树）
 * @param path      要打开的目录路径（建议绝对路径）
 * @param rootNode
 * @param preNode
 * @param currNode
 * @param depth
 */
void ReverseCatalogueToTree(char * path, FileNode * rootNode, FileNode * preNode, FileNode * currNode, int depth){
    struct dirent * currFile;   //当前读取出的文件或目录
    DIR * dirPtr;              //目录
    /*
        函数： DIR * opendir(const char * path);
        获取path目录下的文件和子目录列表，如果path是个文件则返回NULL
    */
    if((dirPtr = opendir(path)) == NULL){
        fprintf(stderr, "无法打开文件夹<%s>\n", path);
        return;
    }
    /*
        函数： struct dirent * readdir(DIR * dir_handle);
        按照ASCII码值从小到大的顺序循环读取dir_handle目录下的文件和子目录（优先读取子目录中的文件和子目录）
    */
    while((currFile = readdir(dirPtr)) != NULL){
        if(strcmp(currFile->d_name, ".") == 0 || strcmp(currFile->d_name, "..") == 0){
            continue;       //跳过名称为"."或".."的目录
        }
        //以下是创建文件树结构的过程
        currNode = FileNodeFactory();                   //创建一个空的文件结点
        strcpy(currNode->fileName, currFile->d_name);   //将当前读取到的文件名赋值给结点的文件名属性
        printf("currNode->fileName:%s\n", currNode->fileName);
        currNode->parent = rootNode;                    //设置当前结点的双亲结点

        if(preNode == NULL){                            //前驱结点为空就创建一个新的前驱结点
            preNode = FileNodeFactory();
        }else{
            preNode->nextSibling = currNode;            //设置前驱结点的兄弟结点为当前结点
            currNode->parent = preNode->parent;         //设置当前结点的双亲为前驱结点的双亲
        }
        if(rootNode->firstChild == NULL){
            rootNode->firstChild = currNode;
            currNode->parent = rootNode;
        }else{
            preNode->nextSibling = currNode;
        }
        //判断是文件夹还是文件
        //获得当前文件的详细信息
        char fullName[1024];
        //拼接字符串
        sprintf(fullName, "%s\\%s", path, currFile->d_name);
        struct stat statInfo;
        if((stat(fullName, &statInfo)) == -1){
            printf(stderr, "无法获得文件<%s>的详细信息！\n", fullName);
            return;
        }
        if((statInfo.st_mode & S_IFMT) == S_IFDIR){
            printf("\t是目录\n");
            currNode->type = TYPE_FOLDER;
            //如果是目录则递归打开
            ReverseCatalogueToTree(fullName, currNode, NULL, NULL, ++depth);

        }else if((statInfo.st_mode & S_IFMT) == S_IFREG){
            printf("\t是一般文件\n");
            printf("所占空间：%ld字节\n", statInfo.st_size);
            currNode->type = TYPE_FILE;
        }
        preNode = currNode;
    }

    closedir(dirPtr);
}
//层序遍历文件树
void ZOrderTraverse(FileTree tree){
    //使用队列记录结点
    LinkedQueue queue;
    InitQueue(&queue);
    enQueue(&queue,tree);//根结点入队

    int zorder = 1;//层号
    printf("\n第%d层：",zorder);
    FileNode* last = tree;
    FileNode* lastchild = tree;
    while(!IsEmpty(&queue)){
        FileNode* node = deQueue(&queue);   //出队
        printf("[%s] ",node->fileName);     //访问出队的结点

        //先将所有孩子结点加入队列
        FileNode *p = node->firstChild;
        while(p){
            enQueue(&queue,p);              //长子及兄弟结点入队
            lastchild = p;
            p = p->nextSibling;             //循环完毕后lastChild指向最后一个兄弟结点
        }
        //所有孩子结点都出队了，并且下一层还有孩子结点，则进入下一层
        if(last == node && !IsEmpty(&queue)){
            last = lastchild;               //last指向入队的最后一个兄弟结点
            zorder++;
            printf("\n第%d层：",zorder);
        }
    }
}

void Visit(FileTree tree,FileNode* node,char (*content)[1000],int *j)
{
    //printf("[%s] [%d]\n",node->filename,zorder);
    int index = *j;

    int flag = 1;
    if(node != tree){
        strcpy(content[index],"\n");//先换一行
        index++;

        /*算法1：递归查找以q为根结点的子树的孩子中，node的祖先结点*/
        FileNode *q = tree;
        while(q != node){
            /*算法2：回溯祖先结点*/
            FileNode *ancestor = node;
            while(ancestor->parent != q){
                ancestor = ancestor->parent;
            }

            /*算法3：给孩子结点编号，记录最后一个目录类型结点及编号和祖先结点的编号*/
            int count = 1;
            int ancestorIndex = 0;
            int lastForderIndex = 0;
            FileNode *lastForderNode = NULL;
            FileNode *p = q->firstChild;
            while(p){
                if(p->type == TYPE_FOLDER){
                    lastForderIndex = count;
                    lastForderNode = p;
                }
                if(p == ancestor){
                    ancestorIndex = count;
                }
                p = p->nextSibling;
                count++;
            }

            /*记录当前结点祖先是否是其父节点最后一个目录类型结点或在它的后面*/
            flag *= 10;
            if(ancestorIndex >= lastForderIndex){
                flag++;
            }

            /*文件类型结点file*/
            if(node->type == TYPE_FILE){
                /*判断其祖先在它所在层中是否在最后一个目录结点之后*/
                if(ancestorIndex < lastForderIndex){
                    strcpy(content[index],"│  ");
                }else{
                    strcpy(content[index],"    ");
                }
                index++;
            }
            /*目录类型结点forder*/
            else if(node->type == TYPE_FOLDER){
                /* 结点的祖先是它所在层的最后一个孩子 */
                if(ancestor != node){
                    if(ancestor != lastForderNode){
                        strcpy(content[index],"│  ");
                    }else{
                        strcpy(content[index],"    ");
                    }
                /* 当前结点是当前层的最后一个孩子 */
                }else{
                    if(node == lastForderNode){
                        strcpy(content[index],"└─");
                    }else{
                        strcpy(content[index],"├─");
                    }
                }
                index++;
            }
            q = ancestor;
        }
    }

    strcpy(content[index],node->fileName);
    index++;

    /*当前文件类型结点是它所在层的最后一个文件类型结点*/
    if(node != tree && node->type == TYPE_FILE
       && (!node->nextSibling || node->nextSibling->type == TYPE_FOLDER)){
        strcpy(content[index],"\n");
        index++;

        /*临时存储打印格式，存储顺序与正常顺序相反*/
        char temp[1000][1000] = {};
        int count = 0;
        /*flag默认值从1开始，因此判断条件大于1即可模拟还原过程*/
        while(flag > 1){
            int state = flag % 10;
            if(state == 0){
                strcpy(temp[count],"│  ");
                count++;
            }else if(state == 1){
                strcpy(temp[count],"    ");
                count++;
            }

            flag = flag / 10;
        }

        /*反序存储*/
        for(int i = count - 1;i >= 0;i--){
            strcpy(content[index],temp[i]);
            index++;
        }
    }

    *j = index;
}

void SaveTreeStructure(FileTree tree)
{
    /*记录文件目录树的树形结构*/
    char content[1000][1000] = {};

    int index = 0;
    strcpy(content[index],"保存的信息如下：\n");
    index++;

    //使用队列记录结点
    LinkedStack stack;
    InitStack(&stack);

    int zorder = 1;//层号
    FileNode *p = tree;
    while(p || !IsLinkedStackEmpty(stack)){
        while(p){
            //访问结点
            Visit(tree,p,content,&index);
            Push(&stack,p);//压栈
            p = p->firstChild;//搜索最左下角的结点
            zorder++;//层序+1
        }

        if(!IsLinkedStackEmpty(stack)){
            Pop(&stack,&p);
            p = p->nextSibling;//搜索兄弟
            zorder--;//层序回溯-1
        }
    }

    //清空上一次的记录
    FILE *fp;
    fp = fopen("c:\\Test\\save.txt","w");
    fclose(fp);

    //以追加的方式记录
    if((fp = fopen("c:\\Test\\save.txt","a+"))==NULL)
    {
        printf("The file %s can not be opened.\n","c:\\Test\\save.txt");
        return;
    }
    for(int i = 0;i < sizeof(content)/sizeof(content[0]);i++){
        fprintf(fp,"%s",content[i]);
        printf("%s",content[i]);
    }
    fclose(fp);
}

void TestFileTree(){
    char * filePath = "C:\\Test";
    DIR * dirPtr;              //当前打开的目录
    if((dirPtr = opendir(filePath)) == NULL){
        fprintf(stderr,"无法打开目录：<%s>\n",filePath);
    }
    //在内存中创建以项目所在目录为文件目录树的链式存储结构
    FileTree tree = FileNodeFactory();
    if(strcmp(filePath, "\0") == 0){
        strcpy(tree->fileName, ".");
        ReverseCatalogueToTree(".", tree, NULL, NULL, 0);
    }else{
        strcpy(tree->fileName, filePath);
        ReverseCatalogueToTree(filePath, tree, NULL, NULL, 0);
    }
    //printf("层序遍历：\n");
    //ZOrderTraverse(tree);
    printf("\n保存信息到文件。。。\n");
    SaveTreeStructure(tree);
}

void PrintDir(char * dir, int depth){
    DIR * dirPtr;                   //DIR结构体类似于FILE，是一个内部结构
    struct dirent * dirContent;     //目录文件，这种文件包含了其他文件的名称及指向这些文件有关信息的指针
    if((dirPtr = opendir(dir)) == NULL){
        sprintf(stderr, "无法打开目录：%s\n", dir);
        return;
    }
    while((dirContent = readdir(dirPtr)) != NULL){
        //跳过文件名为"."和".."的情况
        if (strcmp(dirContent->d_name, ".") == 0 || strcmp(dirContent->d_name, "..") == 0){
            continue;
        }
        char fullName[1024];
        //拼接字符串
        sprintf(fullName, "%s\\%s", dir, dirContent->d_name);
        printf("当前文件名：%s\n", fullName);
        //获得当前文件的详细信息
        struct stat statInfo;
        if((stat(fullName, &statInfo)) == -1){
            printf(stderr, "无法获得文件<%s>的详细信息！\n", fullName);
            return;
        }
        if((statInfo.st_mode & S_IFMT) == S_IFDIR){
            printf("\t是目录\n");
            //如果是目录则递归打开
            PrintDir(fullName, ++depth);
        }else if((statInfo.st_mode & S_IFMT) == S_IFREG){
            printf("\t是一般文件\n");
            printf("所占空间：%ld字节\n", statInfo.st_size);
        }

        //getchar();
    }
    closedir(dirPtr);
}

/*
    Linux下文件操作的几个结构体介绍，在windows下略有不同
    struct _dirstream{//DIR结构体定义
        void * _fd;
        char * _data;
        int _entry_data;
        char * _ptr;
        size_t _alloction;
        size_t _size;
        _libc_lock_define (, _lock)
    };
    typedef struct _dirstream DIR;
    DIR结构体类似于FILE，是一个内部结构。以下几个函数用这个内部结构保存当前正在被读取的目录有关信息。
    函数：DIR * opendir(const char * pathname) 即打开文件目录，返回的就是指向DIR结构体的指针
    这个指针可以由以下几个函数使用：
        struct dirent * readdir(DIR * dirPtr)
        void rewinddir(DIR * dirPtr)
        int closedir(DIR * dirPtr)
        long teldir(DIR * dirPtr)
        void seekdir(DIR * dirPtr, long loc)
    接着是dirent结构体。首先我们要弄清楚目录文件(directory file)的概念：
        这种文件包含了其他文件的名称及指向这些文件有关信息的指针。
        从定义可以看出，dirent不仅仅指向目录，还指向目录中的具体文件，readir函数同样也读取目录下的文件
    以下为dirent结构体的定义：
    struct dirent{
        long d_ino;     //inode number 索引节点号
        off_t d_off;    //offset to this dirent 在目录文件中的偏移
        unsigned short d_reclen;    //length of this d_name 文件名长度
        unsigned char d_type;       //the type of d_name 文件类型
        char d_name[NAME_MAX + 1];  //文件名，最长255个字符
    };
    从上述定义也能够看出来，dirent结构体存储的关于文件的信息很少，所以dirent同样也是起着一个索引的作用，
    如果想获得类似ls -l(windows下 dir命令)那种效果的文件信息，必须要靠stat函数。
    通过readdir函数读取到的文件名存储在结构体dirent的d_name成员中，而函数
        int stat(const char * file_name, struct stat * buf);
        的作用就是获取文件名为d_name的文件的详细信息，存储在stat结构体中，以下为stat结构体的定义：
    struct stat{
        mode_t  st_mode;        //文件类型和访问权限
        ino_t   st_ino;         //索引节点号
        dev_t   st_dev;         //文件使用的设备号
        dev_t   st_rdev;        //设备文件的设备号
        nlink_t st_nlink;       //文件的硬盘连接数
        uid_t   st_uid;         //所有者用户识别号
        gid_t   st_gid;         //组识别号
        off_t   st_size;        //以字节为单位的文件容量
        time_t  st_atime;       //最后一次访问该文件的时间
        time_t  st_mtime;       //最后一次修改该文件的时间
        time_t  st_ctime;       //最后一次改变该文件状态的时间
        blksize_t st_blksize;   //包含该文件的磁盘块的大小
        blkcnt_t  st_blocks;    //该文件所占的磁盘块
    };

    其中， st_mode这个变量用来判断文件类型。
    st_mode是用特征位来表示文件类型的，特征位的定义如下：
        S_IFMT      0170000     文件类型的位遮罩
        S_IFSOCK    0140000     socket
        S_IFLNK     0120000     符号链接(symbolic link)
        S_IFREG     0100000     一般文件
        S_IFBLK     0060000     区块装置(block device)
        S_IFDIR     0040000     目录
        S_IFCHR     0020000     字符装置(character device)
        S_IFIFO     0010000     先进先出(fifo)
        S_ISUID     0004000     文件的(set user-id on execution)位
        S_ISGID     0002000     文件的(set group-id on execution)位
        S_ISVTX     0001000     文件的sticky位
        S_IRWXU     00700       文件所有者的遮罩值(即所有权限值)
        S_IRUSR     00400       文件所有者具可读取权限
        S_IWUSR     00200       文件所有者具可写入权限
        S_IXUSR     00100       文件所有者具可执行权限
        S_IRWXG     00070       用户组的遮罩值(即所有权限值)
        S_IRGRP     00040       用户组具可读取权限
        S_IWGRP     00020       用户组具可写入权限
        S_IXGRP     00010       用户组具可执行权限
        S_IRWXO     00007       其他用户的遮罩值(即所有权限值)
        S_IROTH     00004       其他用户具可读取权限
        S_IWOTH     00002       其他用户具可写入权限
        S_IXOTH     00001       其他用户具可执行权限
    摘自《Linux C 函数库参考手册》
    判断文件类型时，用对文件的st_mode的值与上面给出的值相与，再比较。比如：
        if((statInfo.st_mode & S_IFMT) == S_IFDIR){
            printf("\t是目录\n");
        }else if((statInfo.st_mode & S_IFMT) == S_IFREG){
            printf("\t是一般文件\n");
        }
*/




