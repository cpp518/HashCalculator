// HashCalclator.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	printf("文件路径：%s\n",argv[1]);
	printf("MD5值：");
	md5 *m = new md5(argv[1]);
	delete m;
	printf("SHA1值：");
	sha1 *s = new sha1(argv[1]);
	delete s;
	printf("CRC32值：");
	crc32 *c = new crc32(argv[1]);
	
	return 0;
}

