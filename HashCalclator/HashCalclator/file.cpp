#include "StdAfx.h"
#include "file.h"


file::file(char *fileName)
{
	this->fileHandle = CreateFileA(
		fileName,
		GENERIC_READ,
		FILE_SHARE_DELETE|FILE_SHARE_READ|FILE_SHARE_WRITE,
		0,
		OPEN_EXISTING,
		0,0);
	if(GetLastError() != 0){
		printf("打开文件失败\n");
		this->result = false;
	}
	else{
		this->result = true;
		this->size = GetFileSize(this->fileHandle,NULL);
	}

}

bool file::GetResult(){
	return this->result;
}

HANDLE file::GetFileHandle(){
	return this->fileHandle;
}

DWORD file::GetSize(){
	return this->size;
}

file::~file(void)
{
	//CloseHandle(fileHandle);
}
