#include "FileTree.h"

/** Ϊ�ļ����������ڴ�ռ䣨��㹤�������� */
FileNode * FileNodeFactory(){
    FileNode * node = (FileNode *)malloc(sizeof(FileNode));
    node->type = TYPE_FILE;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    node->parent = NULL;
    return node;
}

/**
 * ���ļ�Ŀ¼�������ڴ棨�����ļ�����
 * @param path      Ҫ�򿪵�Ŀ¼·�����������·����
 * @param rootNode
 * @param preNode
 * @param currNode
 * @param depth
 */
void ReverseCatalogueToTree(char * path, FileNode * rootNode, FileNode * preNode, FileNode * currNode, int depth){
    struct dirent * currFile;   //��ǰ��ȡ�����ļ���Ŀ¼
    DIR * dirPtr;              //Ŀ¼
    /*
        ������ DIR * opendir(const char * path);
        ��ȡpathĿ¼�µ��ļ�����Ŀ¼�б����path�Ǹ��ļ��򷵻�NULL
    */
    if((dirPtr = opendir(path)) == NULL){
        fprintf(stderr, "�޷����ļ���<%s>\n", path);
        return;
    }
    /*
        ������ struct dirent * readdir(DIR * dir_handle);
        ����ASCII��ֵ��С�����˳��ѭ����ȡdir_handleĿ¼�µ��ļ�����Ŀ¼�����ȶ�ȡ��Ŀ¼�е��ļ�����Ŀ¼��
    */
    while((currFile = readdir(dirPtr)) != NULL){
        if(strcmp(currFile->d_name, ".") == 0 || strcmp(currFile->d_name, "..") == 0){
            continue;       //��������Ϊ"."��".."��Ŀ¼
        }
        //�����Ǵ����ļ����ṹ�Ĺ���
        currNode = FileNodeFactory();                   //����һ���յ��ļ����
        strcpy(currNode->fileName, currFile->d_name);   //����ǰ��ȡ�����ļ�����ֵ�������ļ�������
        printf("currNode->fileName:%s\n", currNode->fileName);
        currNode->parent = rootNode;                    //���õ�ǰ����˫�׽��

        if(preNode == NULL){                            //ǰ�����Ϊ�վʹ���һ���µ�ǰ�����
            preNode = FileNodeFactory();
        }else{
            preNode->nextSibling = currNode;            //����ǰ�������ֵܽ��Ϊ��ǰ���
            currNode->parent = preNode->parent;         //���õ�ǰ����˫��Ϊǰ������˫��
        }
        if(rootNode->firstChild == NULL){
            rootNode->firstChild = currNode;
            currNode->parent = rootNode;
        }else{
            preNode->nextSibling = currNode;
        }
        //�ж����ļ��л����ļ�
        //��õ�ǰ�ļ�����ϸ��Ϣ
        char fullName[1024];
        //ƴ���ַ���
        sprintf(fullName, "%s\\%s", path, currFile->d_name);
        struct stat statInfo;
        if((stat(fullName, &statInfo)) == -1){
            printf(stderr, "�޷�����ļ�<%s>����ϸ��Ϣ��\n", fullName);
            return;
        }
        if((statInfo.st_mode & S_IFMT) == S_IFDIR){
            printf("\t��Ŀ¼\n");
            currNode->type = TYPE_FOLDER;
            //�����Ŀ¼��ݹ��
            ReverseCatalogueToTree(fullName, currNode, NULL, NULL, ++depth);

        }else if((statInfo.st_mode & S_IFMT) == S_IFREG){
            printf("\t��һ���ļ�\n");
            printf("��ռ�ռ䣺%ld�ֽ�\n", statInfo.st_size);
            currNode->type = TYPE_FILE;
        }
        preNode = currNode;
    }

    closedir(dirPtr);
}
//��������ļ���
void ZOrderTraverse(FileTree tree){
    //ʹ�ö��м�¼���
    LinkedQueue queue;
    InitQueue(&queue);
    enQueue(&queue,tree);//��������

    int zorder = 1;//���
    printf("\n��%d�㣺",zorder);
    FileNode* last = tree;
    FileNode* lastchild = tree;
    while(!IsEmpty(&queue)){
        FileNode* node = deQueue(&queue);   //����
        printf("[%s] ",node->fileName);     //���ʳ��ӵĽ��

        //�Ƚ����к��ӽ��������
        FileNode *p = node->firstChild;
        while(p){
            enQueue(&queue,p);              //���Ӽ��ֵܽ�����
            lastchild = p;
            p = p->nextSibling;             //ѭ����Ϻ�lastChildָ�����һ���ֵܽ��
        }
        //���к��ӽ�㶼�����ˣ�������һ�㻹�к��ӽ�㣬�������һ��
        if(last == node && !IsEmpty(&queue)){
            last = lastchild;               //lastָ����ӵ����һ���ֵܽ��
            zorder++;
            printf("\n��%d�㣺",zorder);
        }
    }
}

void Visit(FileTree tree,FileNode* node,char (*content)[1000],int *j)
{
    //printf("[%s] [%d]\n",node->filename,zorder);
    int index = *j;

    int flag = 1;
    if(node != tree){
        strcpy(content[index],"\n");//�Ȼ�һ��
        index++;

        /*�㷨1���ݹ������qΪ�����������ĺ����У�node�����Ƚ��*/
        FileNode *q = tree;
        while(q != node){
            /*�㷨2���������Ƚ��*/
            FileNode *ancestor = node;
            while(ancestor->parent != q){
                ancestor = ancestor->parent;
            }

            /*�㷨3�������ӽ���ţ���¼���һ��Ŀ¼���ͽ�㼰��ź����Ƚ��ı��*/
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

            /*��¼��ǰ��������Ƿ����丸�ڵ����һ��Ŀ¼���ͽ��������ĺ���*/
            flag *= 10;
            if(ancestorIndex >= lastForderIndex){
                flag++;
            }

            /*�ļ����ͽ��file*/
            if(node->type == TYPE_FILE){
                /*�ж��������������ڲ����Ƿ������һ��Ŀ¼���֮��*/
                if(ancestorIndex < lastForderIndex){
                    strcpy(content[index],"��  ");
                }else{
                    strcpy(content[index],"    ");
                }
                index++;
            }
            /*Ŀ¼���ͽ��forder*/
            else if(node->type == TYPE_FOLDER){
                /* ���������������ڲ�����һ������ */
                if(ancestor != node){
                    if(ancestor != lastForderNode){
                        strcpy(content[index],"��  ");
                    }else{
                        strcpy(content[index],"    ");
                    }
                /* ��ǰ����ǵ�ǰ������һ������ */
                }else{
                    if(node == lastForderNode){
                        strcpy(content[index],"����");
                    }else{
                        strcpy(content[index],"����");
                    }
                }
                index++;
            }
            q = ancestor;
        }
    }

    strcpy(content[index],node->fileName);
    index++;

    /*��ǰ�ļ����ͽ���������ڲ�����һ���ļ����ͽ��*/
    if(node != tree && node->type == TYPE_FILE
       && (!node->nextSibling || node->nextSibling->type == TYPE_FOLDER)){
        strcpy(content[index],"\n");
        index++;

        /*��ʱ�洢��ӡ��ʽ���洢˳��������˳���෴*/
        char temp[1000][1000] = {};
        int count = 0;
        /*flagĬ��ֵ��1��ʼ������ж���������1����ģ�⻹ԭ����*/
        while(flag > 1){
            int state = flag % 10;
            if(state == 0){
                strcpy(temp[count],"��  ");
                count++;
            }else if(state == 1){
                strcpy(temp[count],"    ");
                count++;
            }

            flag = flag / 10;
        }

        /*����洢*/
        for(int i = count - 1;i >= 0;i--){
            strcpy(content[index],temp[i]);
            index++;
        }
    }

    *j = index;
}

void SaveTreeStructure(FileTree tree)
{
    /*��¼�ļ�Ŀ¼�������νṹ*/
    char content[1000][1000] = {};

    int index = 0;
    strcpy(content[index],"�������Ϣ���£�\n");
    index++;

    //ʹ�ö��м�¼���
    LinkedStack stack;
    InitStack(&stack);

    int zorder = 1;//���
    FileNode *p = tree;
    while(p || !IsLinkedStackEmpty(stack)){
        while(p){
            //���ʽ��
            Visit(tree,p,content,&index);
            Push(&stack,p);//ѹջ
            p = p->firstChild;//���������½ǵĽ��
            zorder++;//����+1
        }

        if(!IsLinkedStackEmpty(stack)){
            Pop(&stack,&p);
            p = p->nextSibling;//�����ֵ�
            zorder--;//�������-1
        }
    }

    //�����һ�εļ�¼
    FILE *fp;
    fp = fopen("c:\\Test\\save.txt","w");
    fclose(fp);

    //��׷�ӵķ�ʽ��¼
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
    DIR * dirPtr;              //��ǰ�򿪵�Ŀ¼
    if((dirPtr = opendir(filePath)) == NULL){
        fprintf(stderr,"�޷���Ŀ¼��<%s>\n",filePath);
    }
    //���ڴ��д�������Ŀ����Ŀ¼Ϊ�ļ�Ŀ¼������ʽ�洢�ṹ
    FileTree tree = FileNodeFactory();
    if(strcmp(filePath, "\0") == 0){
        strcpy(tree->fileName, ".");
        ReverseCatalogueToTree(".", tree, NULL, NULL, 0);
    }else{
        strcpy(tree->fileName, filePath);
        ReverseCatalogueToTree(filePath, tree, NULL, NULL, 0);
    }
    //printf("���������\n");
    //ZOrderTraverse(tree);
    printf("\n������Ϣ���ļ�������\n");
    SaveTreeStructure(tree);
}

void PrintDir(char * dir, int depth){
    DIR * dirPtr;                   //DIR�ṹ��������FILE����һ���ڲ��ṹ
    struct dirent * dirContent;     //Ŀ¼�ļ��������ļ������������ļ������Ƽ�ָ����Щ�ļ��й���Ϣ��ָ��
    if((dirPtr = opendir(dir)) == NULL){
        sprintf(stderr, "�޷���Ŀ¼��%s\n", dir);
        return;
    }
    while((dirContent = readdir(dirPtr)) != NULL){
        //�����ļ���Ϊ"."��".."�����
        if (strcmp(dirContent->d_name, ".") == 0 || strcmp(dirContent->d_name, "..") == 0){
            continue;
        }
        char fullName[1024];
        //ƴ���ַ���
        sprintf(fullName, "%s\\%s", dir, dirContent->d_name);
        printf("��ǰ�ļ�����%s\n", fullName);
        //��õ�ǰ�ļ�����ϸ��Ϣ
        struct stat statInfo;
        if((stat(fullName, &statInfo)) == -1){
            printf(stderr, "�޷�����ļ�<%s>����ϸ��Ϣ��\n", fullName);
            return;
        }
        if((statInfo.st_mode & S_IFMT) == S_IFDIR){
            printf("\t��Ŀ¼\n");
            //�����Ŀ¼��ݹ��
            PrintDir(fullName, ++depth);
        }else if((statInfo.st_mode & S_IFMT) == S_IFREG){
            printf("\t��һ���ļ�\n");
            printf("��ռ�ռ䣺%ld�ֽ�\n", statInfo.st_size);
        }

        //getchar();
    }
    closedir(dirPtr);
}

/*
    Linux���ļ������ļ����ṹ����ܣ���windows�����в�ͬ
    struct _dirstream{//DIR�ṹ�嶨��
        void * _fd;
        char * _data;
        int _entry_data;
        char * _ptr;
        size_t _alloction;
        size_t _size;
        _libc_lock_define (, _lock)
    };
    typedef struct _dirstream DIR;
    DIR�ṹ��������FILE����һ���ڲ��ṹ�����¼�������������ڲ��ṹ���浱ǰ���ڱ���ȡ��Ŀ¼�й���Ϣ��
    ������DIR * opendir(const char * pathname) �����ļ�Ŀ¼�����صľ���ָ��DIR�ṹ���ָ��
    ���ָ����������¼�������ʹ�ã�
        struct dirent * readdir(DIR * dirPtr)
        void rewinddir(DIR * dirPtr)
        int closedir(DIR * dirPtr)
        long teldir(DIR * dirPtr)
        void seekdir(DIR * dirPtr, long loc)
    ������dirent�ṹ�塣��������ҪŪ���Ŀ¼�ļ�(directory file)�ĸ��
        �����ļ������������ļ������Ƽ�ָ����Щ�ļ��й���Ϣ��ָ�롣
        �Ӷ�����Կ�����dirent������ָ��Ŀ¼����ָ��Ŀ¼�еľ����ļ���readir����ͬ��Ҳ��ȡĿ¼�µ��ļ�
    ����Ϊdirent�ṹ��Ķ��壺
    struct dirent{
        long d_ino;     //inode number �����ڵ��
        off_t d_off;    //offset to this dirent ��Ŀ¼�ļ��е�ƫ��
        unsigned short d_reclen;    //length of this d_name �ļ�������
        unsigned char d_type;       //the type of d_name �ļ�����
        char d_name[NAME_MAX + 1];  //�ļ������255���ַ�
    };
    ����������Ҳ�ܹ���������dirent�ṹ��洢�Ĺ����ļ�����Ϣ���٣�����direntͬ��Ҳ������һ�����������ã�
    �����������ls -l(windows�� dir����)����Ч�����ļ���Ϣ������Ҫ��stat������
    ͨ��readdir������ȡ�����ļ����洢�ڽṹ��dirent��d_name��Ա�У�������
        int stat(const char * file_name, struct stat * buf);
        �����þ��ǻ�ȡ�ļ���Ϊd_name���ļ�����ϸ��Ϣ���洢��stat�ṹ���У�����Ϊstat�ṹ��Ķ��壺
    struct stat{
        mode_t  st_mode;        //�ļ����ͺͷ���Ȩ��
        ino_t   st_ino;         //�����ڵ��
        dev_t   st_dev;         //�ļ�ʹ�õ��豸��
        dev_t   st_rdev;        //�豸�ļ����豸��
        nlink_t st_nlink;       //�ļ���Ӳ��������
        uid_t   st_uid;         //�������û�ʶ���
        gid_t   st_gid;         //��ʶ���
        off_t   st_size;        //���ֽ�Ϊ��λ���ļ�����
        time_t  st_atime;       //���һ�η��ʸ��ļ���ʱ��
        time_t  st_mtime;       //���һ���޸ĸ��ļ���ʱ��
        time_t  st_ctime;       //���һ�θı���ļ�״̬��ʱ��
        blksize_t st_blksize;   //�������ļ��Ĵ��̿�Ĵ�С
        blkcnt_t  st_blocks;    //���ļ���ռ�Ĵ��̿�
    };

    ���У� st_mode������������ж��ļ����͡�
    st_mode��������λ����ʾ�ļ����͵ģ�����λ�Ķ������£�
        S_IFMT      0170000     �ļ����͵�λ����
        S_IFSOCK    0140000     socket
        S_IFLNK     0120000     ��������(symbolic link)
        S_IFREG     0100000     һ���ļ�
        S_IFBLK     0060000     ����װ��(block device)
        S_IFDIR     0040000     Ŀ¼
        S_IFCHR     0020000     �ַ�װ��(character device)
        S_IFIFO     0010000     �Ƚ��ȳ�(fifo)
        S_ISUID     0004000     �ļ���(set user-id on execution)λ
        S_ISGID     0002000     �ļ���(set group-id on execution)λ
        S_ISVTX     0001000     �ļ���stickyλ
        S_IRWXU     00700       �ļ������ߵ�����ֵ(������Ȩ��ֵ)
        S_IRUSR     00400       �ļ������߾߿ɶ�ȡȨ��
        S_IWUSR     00200       �ļ������߾߿�д��Ȩ��
        S_IXUSR     00100       �ļ������߾߿�ִ��Ȩ��
        S_IRWXG     00070       �û��������ֵ(������Ȩ��ֵ)
        S_IRGRP     00040       �û���߿ɶ�ȡȨ��
        S_IWGRP     00020       �û���߿�д��Ȩ��
        S_IXGRP     00010       �û���߿�ִ��Ȩ��
        S_IRWXO     00007       �����û�������ֵ(������Ȩ��ֵ)
        S_IROTH     00004       �����û��߿ɶ�ȡȨ��
        S_IWOTH     00002       �����û��߿�д��Ȩ��
        S_IXOTH     00001       �����û��߿�ִ��Ȩ��
    ժ�ԡ�Linux C ������ο��ֲᡷ
    �ж��ļ�����ʱ���ö��ļ���st_mode��ֵ�����������ֵ���룬�ٱȽϡ����磺
        if((statInfo.st_mode & S_IFMT) == S_IFDIR){
            printf("\t��Ŀ¼\n");
        }else if((statInfo.st_mode & S_IFMT) == S_IFREG){
            printf("\t��һ���ļ�\n");
        }
*/




