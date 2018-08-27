#include "StdAfx.h"
#include "base64.h"
#include <math.h>

BYTE base64::base64_table[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
							   'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
							   'a','b','c','d','e','f','g','h','i','j','k','l','m',
							   'n','o','p','q','r','s','t','u','v','w','x','y','z',
							   '0','1','2','3','4','5','6','7','8','9','+','/'};
base64::base64(char *str,bool type)
{
	this->flag = type;
	if(type){
		
		this->encode(str);
	}
	else{
		this->decode(str);
	}
	printf("\n");
}


base64::~base64(void)
{
	if(flag){
		delete[] this->buffer;
		delete this->realSize;
		delete this->bufferSize;
	}
	else{
		delete this->realSize;
	}
}

void base64::FillMessage(char *str){
	for(DWORD i=0;i<(*this->realSize);i++){
		this->buffer[i] = str[i];
	}
	for(DWORD i=(*this->realSize);i<(*this->bufferSize);i++){
		this->buffer[i] = 0;
	}

}


void base64::encode(char *str){
	this->realSize = new DWORD;
	this->bufferSize = new DWORD;
	BYTE *strr = new BYTE[30];
	*this->realSize = (DWORD)strlen(str);
	*this->bufferSize = *this->realSize;
	while(*this->bufferSize%3!=0){
		(*this->bufferSize)++;
	}
	int total = 0;
	this->buffer = new BYTE[(*this->bufferSize)/3*4];
	this->FillMessage(str);
	char a[9];
	for(DWORD i=0;i<(*this->bufferSize);i+=3){
		int sum = 0;
		
		for(DWORD j=i;j<i+3;j++){
			for(int k=0;k<8;k++){
					a[k]='0';
				}
				int jj = 7;
				while(this->buffer[j]>0){
    				a[jj] = this->buffer[j]%2 + 48;
    				this->buffer[j]/=2;
    				jj--;
    			}
				a[8] = '\0';
				sprintf((char*)strr+(j-i)*8,"%s",a);//拼接字符串
			}
		
			for(int j=0;j<24;j+=6){
				sum = 0;
				for(int k=j;k<j+6;k++){
					if(strr[k]=='1'){
						sum+=pow(2.0,(5-k+j));
					}
				}
				printf("%c",base64_table[sum]); 
				total++;
				if((total+(*this->bufferSize)-(*this->realSize))==(*this->bufferSize)/3*4){
					break;
				}
			} 
	}
	delete []strr;
	for(DWORD i=0;i<((*this->bufferSize)-(*this->realSize));i++){
		printf("=");
	}
	
}

void base64::decode(char *str)
{
	
	this->realSize = new DWORD;
	*this->realSize = strlen(str);
	char *strr = new char[40];
	char a[9];

	//每组有效的位置
	int start[3][8]={{2,3,4,5,6,7,10,11},{12,13,14,15,18,19,20,21},{22,23,26,27,28,29,30,31}};
	
	for(int i=0;i<(*this->realSize);i+=4){
		for(int j=i;j<i+4;j++){
			for(int k=0;k<8;k++){
					a[k]='0';
				}
				int jj = 7;
				int findNum = this->find(str[j]);
				if(findNum==65)findNum=0;
				while(findNum>0){
    				a[jj] = findNum%2 + 48;
    				findNum/=2;
    				jj--;
    			}
				a[8] = '\0';
				sprintf((char*)strr+(j-i)*8,"%s",a);
			
		}	
		//获取需要解密的字符串每一组的二进制值
		//重新组合各位置的二进制值来得出明文
		int sum;
		for(int j=0;j<3;j++){
			sum = 0;
			for(int k=0;k<8;k++){
				sum+=(strr[start[j][k]]-'0')*pow(2.0,7-k);
			}
			if(sum==0){
				break;
			}
			else{
				printf("%c",sum);
			}
		}
	}
	delete[] strr;
}

int base64::find(char c){
	int result = 65;
	for(int i=0;i<64;i++){
		if(base64_table[i] == c){
			result = i;
			break;
		}
	}
	return result;
}