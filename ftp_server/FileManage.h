#ifndef _FILEMANAGE_H_
#define _FILEMANAGE_H_
int list_file(int sod);
void download(int sfd, char *file);//�ϴ�
void upload(int sfd, char *file, int mode);//����
void sem_p(int sid);//����p����
void sem_v(int sid);//����v����
void *get_shm(int shm_id);//ȡ�ù����ڴ�id
int creat_shm();//���������ڴ�
void init_semval(int sem_id);//��ʼ���ź���
int  sem_create();//�����ź���
#endif


















