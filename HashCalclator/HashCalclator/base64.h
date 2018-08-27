#pragma once
class base64
{
public:
	base64(char* str,bool type); //type ������encode����decode

	~base64(void);

private:

	void FillMessage(char *str);
	void encode(char *str);
	void decode(char *str);
	int find(char c);

	static BYTE base64_table[64];

	bool flag;
	BYTE *buffer;
	DWORD *realSize;
	DWORD *bufferSize;
};

