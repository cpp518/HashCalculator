// HashCalclator.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	printf("�ļ�·����%s\n",argv[1]);
	printf("MD5ֵ��");
	md5 *m = new md5(argv[1]);
	delete m;
	printf("SHA1ֵ��");
	sha1 *s = new sha1(argv[1]);
	delete s;
	printf("CRC32ֵ��");
	crc32 *c = new crc32(argv[1]);
	
	return 0;
}

