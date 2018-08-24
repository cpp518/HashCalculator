#pragma once
class file
{
public:
	file(char *fileName);
	~file(void);
	bool GetResult();
	
	DWORD GetSize();
	HANDLE GetFileHandle();

private:
	bool result;
	
	DWORD size;
	
	HANDLE fileHandle;
};

