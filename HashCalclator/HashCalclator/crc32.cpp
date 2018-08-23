#include "StdAfx.h"
#include "crc32.h"

DWORD crc32::ploy = 0xEDB88320;
DWORD crc32::initValue = 0xFFFFFFFF;
DWORD crc32::endValue = 0xFFFFFFFF;

crc32::crc32(void){}

void crc32::init(){
	for(int i = 0;i<256;i++){
		DWORD temp = i;
		for(int j=0;j<8;j++){
			if(temp&1){
				temp = (temp>>1)^ploy;
			}
			else{
				temp>>=1;
			}
		}
		this->crc32_table[i] = temp;
	}
}

void crc32::calc(){


}

crc32::crc32(char* fileName)
{
	HANDLE file = CreateFileA(
		fileName,
		GENERIC_READ,
		FILE_SHARE_DELETE|FILE_SHARE_READ|FILE_SHARE_WRITE,
		0,
		OPEN_EXISTING,
		0,0);

	if(GetLastError() != 0){
		printf("打开文件失败\n");
		this->open = false;
	}
	else{
		this->open = true;
		this->crc32_table = new DWORD[256];
		crc32::init();
		DWORD size = GetFileSize(file,NULL);
		this->realSize = new DWORD;
		this->buffer = new BYTE[size+10];
		ReadFile(file,buffer,size,realSize,NULL);
		DWORD remain = initValue;
		for(int pos = 0;pos<size;pos++){
			DWORD j = (remain&0xFF)^*(DWORD*)&this->buffer[pos];
			remain = (remain>>8)^crc32_table[j%256];
		}
		remain = remain^endValue;
		printf("%X\n",remain);
		CloseHandle(file);
	}
}



crc32::~crc32(void)
{
	if(this->open){
		delete this->crc32_table;
		delete this->buffer;
		delete this->realSize; 
	}
}
