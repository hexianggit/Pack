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
	//第一个参数:包路径 第二个参数：打包目录路径 第三个参数：解包路径
	Pack pack(_T("D:\\anydream\\pack.dat"), _T("D:\\anydream\\src"),_T("D:\\anydream\\ss"));
	//打包目录
	pack.PackFileandDire();
	//解包目录
	pack.UnPackFileandDire();
	system("pause");
}