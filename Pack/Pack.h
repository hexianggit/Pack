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


//文件外部信息
typedef struct info
{
	tchar_t name[100];//文件名
	tchar_t path[100];//文件路劲
	int type;//文件类型
	int len;//文件内容长度
}INFO;


class Pack
{
public:
	Pack(const String &pn, const String &dn, const String &ud);
	~Pack();

	void PackFileandDire();
	void UnPackFileandDire();
private:

	//设置外部信息集合
	void GitInfo(String &name);
	//获取文件类型
	int GettType(String &name);
	//获取文件内容长度
	int GetLen(String &name);
	//获取根目录名
	void SetRoot(String &name);


	String PackName; //包文件路径
	String DireName; //打包目录路径
	String UnPackName; //解包目录路径

	vector<INFO> info; //外部信息集合


	int size; //文件内容长度
	String rootName; //根目录名
	char *content; //文件内容
};

