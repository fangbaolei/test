#ifndef _CONFIG_H_
#define _CONFIG_H_
/***********�������ļ�����Ϣ���뵽ȫ�ֽṹ����***********/
typedef struct _CONFIG
{
	int up_rate;//��maxlenȷ���µ��ϴ��ٶ�
	int down_rate;//��maxlenһ���µ��������ٶ�
	int time_late;//��ʱ��ʱ��
	int port;//�������Ķ˿ں�
	int able_down;//�Ƿ�֧������
	int able_up;//�Ƿ�֧���ϴ�
	int able_mkdir;//�Ƿ�֧�ִ���Ŀ¼
	int maxclient;//���ӵĿͻ�����
	int maxlen;//read�������׽�����һ���Զ�ȡ������ֽ�
}_FTP_CONFIG;
_FTP_CONFIG ftp_cfg;
int Readcfg(char *filename);//�������ļ�����Ϣ����ȫ�ֽṹ����
int GetPart(char str1[100],char t[100],int len);//��ȡÿ����Ԫ��������Ϣ
#endif














