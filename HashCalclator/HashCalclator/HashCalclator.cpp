// HashCalclator.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	printf("文件路径：%s\n",argv[1]);
	printf("MD5值： ");
	md5 t(argv[1]);
	return 0;
}

