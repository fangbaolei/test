#ifndef _FTPCOMD_
#define _FTPCOMD_
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/select.h>
#include <errno.h>
#include <dirent.h>
typedef struct _FTPCMD
{
	char *command;
	int (*do_cmd) (int,char s[512]);
} FTPCMD;
typedef struct _FILESTATA
{
	int download_count;//���ص�ͳ���ļ���
	int upload_count;//�ϴ���ͳ���ļ���
	size_t download_byte;//���ص��ܹ��ֽ���
	size_t upload_byte;//�ϴ����ܹ��ֽ���
} Filedownup;
typedef struct _STAT
{
	int datasize;//����׽����������ֽ�
	char user[24];	 //�û���
	char pwd[24];  //����
	int login_flag;	//��½��־
	uid_t uid;		//uid
	gid_t gid;		//gid
	char root_dir[48];	//�û���Ŀ¼
	size_t rest_offset;	//�ϴ�����ƫ����
	int data_conect_type;	 //������������ PORT PASV
	char port_ip[16];		//IP��ַ��PORTԶ�ˣ�PASV���أ�
	unsigned short port_port;	 //�˿ڣ�PORTԶ�ˣ�PASV���أ�
	pid_t data_conn_pid;	//�������ӽ���PID
	int sevice_sockd;
	int ctrl_conn_sfd;		//��������FD
	int pasv_sfd;		//PASV����FD
	int port_sfd;
	char renamefile[128]; //������Ŀ���ļ���
	int sem_id;			//�ź���ID
	int shm_id; //�����ڴ�ID
	struct sockaddr_in client;
} STATUS;
#define PORT                  1
#define PASV                  2
#define FTP_LISTDATA          150
#define FTP_NOOPOK            200
#define FTP_TYPEOK            200
#define FTP_PORTOK            200
#define FTP_EPRTOK            200
#define FTP_UMASKOK           200
#define FTP_CHMODOK           200
#define FTP_EPSVALLOK         200
#define FTP_STRUOK            200
#define FTP_MODEOK            200
#define FTP_PBSZOK            200
#define FTP_PROTOK            200
#define FTP_ALLOOK            202
#define FTP_FEAT              211
#define FTP_STATOK            211
#define FTP_SIZEOK            213
#define FTP_MDTMOK            213
#define FTP_STATFILE_OK       213
#define FTP_SITEHELP          214
#define FTP_HELP              214
#define FTP_SYSTOK            215

#define FTP_GRIVEUSER         220
#define FTP_GOODBYE           221
#define FTP_ABOR_NOCONN       225
#define FTP_TRANSFEROK        226
#define FTP_ABOROK            226
#define FTP_PASVOK            227
#define FTP_EPSVOK            229
#define FTP_LOGINOK           230
#define FTP_AUTHOK            234
#define FTP_CWDOK             250
#define FTP_RMDIROK           250//ɾ��Ŀ¼
#define FTP_DELEOK            250//ɾ���ļ�
#define FTP_RENAMEOK          250//������
#define FTP_PWDOK             257//��ӡ����ǰ��Ŀ¼
#define FTP_MKDIROK           257//����Ŀ¼�ɹ�������

#define FTP_GIVEPWORD         331
#define FTP_RESTOK            350
#define FTP_RNFROK            350

#define FTP_IDLE_TIMEOUT      421
#define FTP_DATA_TIMEOUT      421
#define FTP_TOO_MANY_USERS    421
#define FTP_IP_LIMIT          421
#define FTP_IP_DENY           421
#define FTP_TLS_FAIL          421
#define FTP_BADSENDCONN       425
#define FTP_BADSENDNET        426
#define FTP_BADSENDFILE       451

#define FTP_BADCMD            500
#define FTP_BADOPTS           501
#define FTP_COMMANDNOTIMPL    502
#define FTP_NEEDUSER          503
#define FTP_NEEDRNFR          503
#define FTP_BADPBSZ           503
#define FTP_BADPROT           503
#define FTP_BADSTRU           504
#define FTP_BADMODE           504
#define FTP_BADAUTH           504
#define FTP_NOSUCHPROT        504
#define FTP_NEEDENCRYPT       521
#define FTP_EPSVBAD           522
#define FTP_DATATLSBAD        522
#define FTP_INCORRECT         530
#define FTP_NOHANDLEPROT      536
#define FTP_FILEFAIL          550
#define FTP_NOPERM            550
#define FTP_UPLOADFAIL        553
/********�������******/
int do_user(int, char *);
int do_pasd(int nsfd, char *password);
int do_type(int sfd, char mode[512]);
int do_cwd(int, char *);
int do_cdup(int, char *);
int do_syst(int, char *);
int do_pwd(int, char *);
int do_rest(int sfd, char*);
int do_port(int, char *);
int do_list(int, char *);
int do_nlst(int, char *);
int do_rmd(int, char *);
int do_mkd(int, char *);
int do_dele(int, char *);
int do_rein(int, char *);
int do_help(int, char *);
int do_quit(int, char *);
int do_rest(int, char *);
int do_pasv(int sfd,char ifo[512]);
int do_rnfr(int, char *);
int do_rnto(int, char *);
int do_size(int, char *);
int do_noop(int, char *);
int do_stor(int, char *);
int do_retr(int, char *);
int do_appe(int, char *);
int do_abor(int, char *);
int do_stat(int, char *);
int do_mode(int, char *);
int do_chmod(int,char *);
void Sentcomd(int comd_id,int sfd,char com_msg[512]);
void GetComd(int sockd,char cmd[7],char message[256]);
int SelectCmd(int sockd);
void init_do_comd(int scd);
int change_dir(const char dest_dir[512]);
void Getcurrentdir(char dir[512]);
uid_t check_anonymous();//��������û��ĵ���
uid_t check_user(char *username,char *password);//���������û��ĵ���
int Cmd_operater(int sockd);//���������Ƿ�ƥ�䲢������Ӧ�Ĳ���
#endif




















