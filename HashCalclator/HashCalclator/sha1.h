#pragma once
#include <Windows.h>
class sha1
{
public:
	sha1(HANDLE,DWORD);
	~sha1(void);

private:
	static DWORD A;
	static DWORD B;
	static DWORD C;
	static DWORD D;
	static DWORD E;
	static DWORD k[4];


	DWORD *realSize;
	DWORD *Size;
	DWORD *result;
	DWORD *M;
	BYTE  *buffer;
	
	
	void FillMessage() ; //�����Ϣ��ʹ����������Ҫ��
	void ShowMessage() ; //�����Ϣ��������û�д�
	void SeparateMessage(DWORD begin);
};  

