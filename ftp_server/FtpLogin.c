#include "FtpLogin.h"
#include "string.h"
#include <stdio.h>

int check_ip_right(char *ip_port)//���ip�Ƿ���ȷ
{
	int i, len = strlen(ip_port),num = 0;
	int ip_1, ip_2, ip_3, ip_4, port_h, port_l;
	for(i=0;i<len;i++)
	{
		if (!isdigit(ip_port[i]) && ip_port[i] != ',')
			return 0;
		else if (ip_port[i] == ',')
			num++;
	}
	if (strstr(ip_port, ",,") != NULL)
		return 0;
	if (num != 5)
		return 0;
	sscanf(ip_port, "%d,%d,%d,%d,%d,%d", &ip_1, &ip_2, &ip_3, &ip_4, &port_h, &port_l);
	if (ip_1>= 255 || ip_2 >= 255 || ip_3 >= 255 || ip_4 >= 255 \
		|| port_l >= 255 || port_h >= 255 || (port_h==0 && port_l==0))
		return 0;
	return 1;
}
unsigned short  trace_ip_port(char *source, char *ip_address)//port ģʽ��ת��ip��ַ�Ͷ˿ں�
{
	int ip_1, ip_2, ip_3, ip_4, port_h, port_l;
	sscanf(source, "%d,%d,%d,%d,%d,%d", &ip_1, &ip_2, &ip_3, &ip_4, &port_h, &port_l);
	sprintf(ip_address, "%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
	return (unsigned short )(port_h * 256 + port_l);
}
int trace_pasv_ip(char *dest, char *ip_address,unsigned short port)//pasvģʽ��ת��ip��ַ�Ͷ˿ں�
{
	int ip_1, ip_2, ip_3, ip_4;
	sscanf(ip_address, "%d.%d.%d.%d", &ip_1, &ip_2, &ip_3, &ip_4);
	sprintf(dest, "%d,%d,%d,%d,%d,%d", ip_1, ip_2, ip_3, ip_4, port/256, port%256);
	return 1;
}
void Trancetosmall(char *str)//���ַ����ڵ���ĸȫ��ת��ΪСд
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=tolower(str[i]);
	}
}
void Ttancetobig(char *str)//���ַ����ڵ���ĸȫ��ת��Ϊ��д
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=toupper(str[i]);
	}
}


































