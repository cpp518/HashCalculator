// HashCalclator.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	printf("�ļ�·����%s\n",argv[1]);
	file *f = new file(argv[1]);
	if(f->GetResult()!=true){
		return 1;
	}
	printf("MD5ֵ��");
	md5 *m = new md5(f->GetFileHandle(),f->GetSize());
	delete m;
	printf("SHA1ֵ��");
	sha1 *s1 = new sha1(f->GetFileHandle(),f->GetSize());
	delete s1;
	printf("CRC32ֵ��");
	crc32 *c = new crc32(f->GetFileHandle(),f->GetSize());
	delete c;
	delete f;
	return 0;
}

