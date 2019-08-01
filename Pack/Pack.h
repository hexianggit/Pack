#pragma once
#include <abprec.h>
#include <vector>
#include <iostream>
#include <lang/string.h>
#include <io/directory.h>
#include <io/file.h>
#include <cflprec.h>
#include <errno.h>
#include <io/bufferinput.h>
#include <io/bufferoutput.h>
#include <io/fileinput.h>
#include <time.h>

using namespace cpp::lang;
using namespace cpp::io;
using namespace std;


//�ļ��ⲿ��Ϣ
typedef struct info
{
	tchar_t name[100];//�ļ���
	tchar_t path[100];//�ļ�·��
	int type;//�ļ�����
	int len;//�ļ����ݳ���
}INFO;


class Pack
{
public:
	Pack(const String &pn, const String &dn, const String &ud);
	~Pack();

	void PackFileandDire();
	void UnPackFileandDire();
private:

	//�����ⲿ��Ϣ����
	void GitInfo(String &name);
	//��ȡ�ļ�����
	int GettType(String &name);
	//��ȡ�ļ����ݳ���
	int GetLen(String &name);
	//��ȡ��Ŀ¼��
	void SetRoot(String &name);


	String PackName; //���ļ�·��
	String DireName; //���Ŀ¼·��
	String UnPackName; //���Ŀ¼·��

	vector<INFO> info; //�ⲿ��Ϣ����


	int size; //�ļ����ݳ���
	String rootName; //��Ŀ¼��
	char *content; //�ļ�����
};

