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
#include "Pack.h"

using namespace cpp::lang;
using namespace cpp::io;
using namespace std;


int main(int argc, char **argv)
{
	//��һ������:��·�� �ڶ������������Ŀ¼·�� ���������������·��
	Pack pack(_T("D:\\anydream\\pack.dat"), _T("D:\\anydream\\src"),_T("D:\\anydream\\ss"));
	//���Ŀ¼
	pack.PackFileandDire();
	//���Ŀ¼
	pack.UnPackFileandDire();
	system("pause");
}