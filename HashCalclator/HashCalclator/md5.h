#include <Windows.h>
#pragma once
class md5
{
public:
	
	md5(char* fileName);

	~md5(void);

private: 
	char* fileName;
	bool open;
	BYTE *buffer; //���������ݱ���λ��
	DWORD *realSize; //ʵ�ʶ�����ļ���С
	DWORD *result;  //�������λ��
	DWORD *Size;    //�����Ϣ�����Ϣ��С
	DWORD *M ;      //��������ÿ��Ҫ�����64���ֽ�
	//������MD5�Ǵ���ֽ����ʾ������Ҫ��������
	static DWORD A ;
	static DWORD B ;
	static DWORD C ;
	static DWORD D ;
	static DWORD T[64];		//����ֵ
	static DWORD s[64];		//���Ƶ�λ��
	static DWORD m[64];		//ÿ�δ���ķֶ�˳��

	void FillMessage() ; //�����Ϣ��ʹ����������Ҫ��
	void ShowMessage() ; //�����Ϣ��������û�д�
	void SeparateMessage(DWORD begin); //����Ϣ�ֳ�16�ݣ��浽M��
	void FF(DWORD &a,DWORD &b,DWORD &c,DWORD &d,DWORD mj,DWORD s,DWORD ti);
	void GG(DWORD &a,DWORD &b,DWORD &c,DWORD &d,DWORD mj,DWORD s,DWORD ti);
	void HH(DWORD &a,DWORD &b,DWORD &c,DWORD &d,DWORD mj,DWORD s,DWORD ti);
	void II(DWORD &a,DWORD &b,DWORD &c,DWORD &d,DWORD mj,DWORD s,DWORD ti);
	DWORD F(DWORD X,DWORD Y,DWORD Z);
	DWORD G(DWORD X,DWORD Y,DWORD Z);
	DWORD H(DWORD X,DWORD Y,DWORD Z);
	DWORD I(DWORD X,DWORD Y,DWORD Z);
};

