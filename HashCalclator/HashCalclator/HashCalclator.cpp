// HashCalclator.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	if(argc<2){printf("��������ʹ��-help��ѯ��ع���\n");}
	else if(!strcmp(argv[1],"-hash")){
		printf("�ļ�·����%s\n",argv[2]);
		file *f = new file(argv[2]);
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
	}
	else if(!strcmp(argv[1],"-base64")){
		if(!strcmp(argv[2],"-encode")){
			printf("base64���ܣ�");
			base64 *b64 = new base64(argv[3],1);
			delete b64;
		}
		else if(!strcmp(argv[2],"-decode")){
			printf("base64���ܣ�");
			base64 *b64 = new base64(argv[3],0);
			delete b64;
		}
		else{
			printf("��������ʹ��-help��ѯ��ع���\n");
		}

	}
	else if(!strcmp(argv[1],"-des")){
		if(strcmp(argv[2],"-encode")){
			
		}
		else if(strcmp(argv[2],"-decode")){
			
		}
		else{
			printf("��������ʹ��-help��ѯ��ع���\n");
		}
	}
	else if(!strcmp(argv[1],"-help")){
		printf("\n\n-------------------------------------------------------------------------\n");
		printf("����˵��                                                                \n");
		printf("-------------------------------------------------------------------------\n");
		printf(" -hash [�ļ�·��]		                        ��ѯ�ļ���hashֵ\n");
		printf(" -base64 [-encode/-decode][��Ϣ����]         ����Ϣ����base64���ܻ��߽���\n");
		printf(" -des [-encode/-decode][��Կ][��Ϣ����]       ����Ϣ����DES���ܻ��߽���\n");		
		printf("-------------------------------------------------------------------------\n");
	}
	else{
		printf("��������ʹ��-help��ѯ��ع���\n");
	}
	return 0;
}

