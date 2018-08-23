#pragma once
class crc32
{
public:
	crc32(void);
	crc32(char* fileName);
	~crc32(void);

	
private:
	void init();
	void calc();
	
	static DWORD ploy;
	static DWORD initValue;
	static DWORD endValue;
	
	BYTE *buffer;
	DWORD *realSize;
	DWORD *crc32_table;
	
	bool open;
};

