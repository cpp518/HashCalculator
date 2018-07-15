#include <Windows.h>
#pragma once
class md5
{
public:
	
	md5(char* fileName);

	~md5(void);

private: 
	char* fileName;

	BYTE *buffer; //这里是内容保存位置
	DWORD *realSize; //实际读入的文件大小
	DWORD *result;  //结果保存位置
	DWORD *Size;    //填充信息后的信息大小
	DWORD *M ;      //用来保存每次要处理的64个字节
	//由于是MD5是大端字节序表示，所以要反过来存
	const static DWORD A = 0x67452301;
	const static DWORD B = 0xEFCDAB89;
	const static DWORD C = 0x98BADCFE;
	const static DWORD D = 0x10325476;

	void FillMessage() ; //填充信息，使得内容满足要求
	void ShowMessage() ; //输出信息，看看有没有错
	void SeparateMessage(DWORD begin); //将信息分成16份，存到M中
};

