// HashCalclator.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	printf("�ļ�·����%s\n",argv[1]);
	printf("MD5ֵ�� ");
	md5 t(argv[1]);
	return 0;
}

