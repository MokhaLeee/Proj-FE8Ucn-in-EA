#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned int u32;
typedef unsigned char u8;

char* h2s(u32 hsrc);

int main(){
	char* fileName = "IncStr.event";
	FILE* fp = fopen( fileName,"a");
	
	//for( u32 i = 0x01A0; i<0x026F; i++)
	//for( u32 i = 0x2BF; i<0x308; i++)
	//for( u32 i = 0x354; i<0x403; i++)
	for( u32 i = 0x4E5; i<0x51F; i++)
	{
		char* str = h2s(i);
		printf("%s",str);
		u8 len = strlen(str);
		
		char* _str = (char*)malloc( strlen(str)+4 );
		strcpy(_str,str);
		
		_str[len++] = '.';
		_str[len++] = 't';
		_str[len++] = 'x';
		_str[len++] = 't';
		_str[len++] = '\0';
		
		char* StrFile = (char*)malloc( strlen(_str) );
		strcpy(StrFile,_str);
		free(_str);
		
		fputs("ALIGN 4\nSetStr($",fp);
		fputs(str,fp);
		fputs(",STR_",fp);
		fputs(str,fp);
		fputs(")\nSTR_",fp);
		fputs(str,fp);
		fputs(":\n",fp);
		fputs("#incbin ",fp);
		fputs(str,fp);
		fputs(".txt\n",fp);
		fputs("StrEnd\n\n",fp);
	}	
	
	fclose(fp);
	return 0;
}