#include "StdAfx.h"
#include "md5.h"


md5::md5(char* fileName)
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
		
	}
	else{
		DWORD size = GetFileSize(file,NULL);

		this->buffer = new BYTE[size*64];
		this->realSize = new DWORD;
		this->Size = new DWORD;
		this->result = new DWORD[4];
		this->M = new DWORD[16];
		ReadFile(file,buffer,size,realSize,NULL);
		FillMessage();
		ShowMessage();
		this->result[0] = md5::A;
		this->result[1] = md5::B;
		this->result[2] = md5::C;
	    this->result[3] = md5::D;
		for(DWORD i = 0;i<(*(this->Size) / 64);i++){	//每一次处理64字节（512位）
		    SeparateMessage(i*64);
		}
	}
/*	printf("%d",*realSize);
	for(DWORD i=0;i<(*realSize);i++){
		printf("%c",buffer[i]);
	}
	printf("\n");*/
}


md5::~md5(void)
{
	delete[] buffer;
	delete[] result;
	delete realSize;
	delete Size;
}

void md5::FillMessage(){
	DWORD pos = *(this->realSize);
	if(*(this->realSize)% 64 != 56){
		buffer[pos++] = 0x80;
	}
	while(pos % 64 != 56){
		buffer[pos++] = 0;
	}
	buffer[pos++] = *(this->realSize)*8 & 0x000000FF;
	buffer[pos++] = *(this->realSize)*8 & 0x0000FF00;
	buffer[pos++] = *(this->realSize)*8 & 0x00FF0000;
	buffer[pos++] = *(this->realSize)*8 & 0xFF000000;
	buffer[pos++] = 0;
	buffer[pos++] = 0;
	buffer[pos++] = 0;
	buffer[pos++] = 0;
	*(this->Size) = pos;
}

void md5::ShowMessage(){
	for(DWORD i = 0;i<*(this->Size);i++){
	    
		if(i!=0 && i%16==0){
		    printf("\n");
		}
		printf("%02X ",buffer[i]);
	}
	printf("\n%d",*(this->Size));
}

void md5::SeparateMessage(DWORD begin){
	
	for(DWORD i = 0;i<16;i++){
	    this->M[i] = buffer[begin]|buffer[begin+1]*0x100|buffer[begin+2]*0x10000|buffer[begin+3]*0x1000000;
	/*	if(i%4==0)
			printf("\n");
		printf("%X ",this->M[i]);*/
		begin+=4;
	}
}