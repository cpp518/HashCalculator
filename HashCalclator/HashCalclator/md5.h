#include <Windows.h>
#pragma once
class md5
{
public:
	
	md5(char* fileName);

	~md5(void);

private: 
	char* fileName;

	BYTE *buffer; //���������ݱ���λ��
	DWORD *realSize; //ʵ�ʶ�����ļ���С
	DWORD *result;  //�������λ��
	DWORD *Size;    //�����Ϣ�����Ϣ��С
	DWORD *M ;      //��������ÿ��Ҫ�����64���ֽ�
	//������MD5�Ǵ���ֽ����ʾ������Ҫ��������
	const static DWORD A = 0x67452301;
	const static DWORD B = 0xEFCDAB89;
	const static DWORD C = 0x98BADCFE;
	const static DWORD D = 0x10325476;

	void FillMessage() ; //�����Ϣ��ʹ����������Ҫ��
	void ShowMessage() ; //�����Ϣ��������û�д�
	void SeparateMessage(DWORD begin); //����Ϣ�ֳ�16�ݣ��浽M��
};

