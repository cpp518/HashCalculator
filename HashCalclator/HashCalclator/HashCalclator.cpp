// HashCalclator.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	if(argc<2){printf("参数错误，使用-help查询相关功能\n");}
	else if(!strcmp(argv[1],"-hash")){
		printf("文件路径：%s\n",argv[2]);
		file *f = new file(argv[2]);
		if(f->GetResult()!=true){
			return 1;
		}
		printf("MD5值：");
		md5 *m = new md5(f->GetFileHandle(),f->GetSize());
		delete m;
		printf("SHA1值：");
		sha1 *s1 = new sha1(f->GetFileHandle(),f->GetSize());
		delete s1;
		printf("CRC32值：");
		crc32 *c = new crc32(f->GetFileHandle(),f->GetSize());
		delete c;
		delete f;
	}
	else if(!strcmp(argv[1],"-base64")){
		if(!strcmp(argv[2],"-encode")){
			printf("base64加密：");
			base64 *b64 = new base64(argv[3],1);
			delete b64;
		}
		else if(!strcmp(argv[2],"-decode")){
			printf("base64解密：");
			base64 *b64 = new base64(argv[3],0);
			delete b64;
		}
		else{
			printf("参数错误，使用-help查询相关功能\n");
		}

	}
	else if(!strcmp(argv[1],"-des")){
		if(strcmp(argv[2],"-encode")){
			
		}
		else if(strcmp(argv[2],"-decode")){
			
		}
		else{
			printf("参数错误，使用-help查询相关功能\n");
		}
	}
	else if(!strcmp(argv[1],"-help")){
		printf("\n\n-------------------------------------------------------------------------\n");
		printf("帮助说明                                                                \n");
		printf("-------------------------------------------------------------------------\n");
		printf(" -hash [文件路径]		                        查询文件的hash值\n");
		printf(" -base64 [-encode/-decode][消息内容]         将消息进行base64加密或者解密\n");
		printf(" -des [-encode/-decode][密钥][消息内容]       将消息进行DES加密或者解密\n");		
		printf("-------------------------------------------------------------------------\n");
	}
	else{
		printf("参数错误，使用-help查询相关功能\n");
	}
	return 0;
}

