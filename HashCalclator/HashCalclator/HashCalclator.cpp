// HashCalclator.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	printf("�ļ�·����%s\n",argv[3]);
	printf("MD5ֵ��");
	md5 *m = new md5(argv[3]);
	delete m;
	printf("SHA1ֵ��");
	sha1 *s = new sha1(argv[3]);
	delete s;
	return 0;
}

