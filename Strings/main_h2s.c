#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned int u32;
typedef unsigned char u8;

char* h2s(u32 hsrc)
{
	char* str = (char*)malloc(1);
	char* _str = (char*)malloc(1);
	u32 hex = hsrc;
	
	u8 i=0;
	while( 0 != hex)
	{
		_str = (char*)malloc(i+2);
		strcpy(_str, str);
		free(str);
		str = (char*)malloc(i+2);
		strcpy(str, _str);
		free(_str);
		
		if( 0xA > hex%0x10  )
			str[i] = hex%0x10 + 0x30;
		else
			str[i] = hex%0x10 + 0x37;
		hex = hex/0x10;
		i++;
	}
	
	// 补个0
	if( 3==i )
	{
		_str = (char*)malloc(i+2);
		strcpy(_str, str);
		free(str);
		str = (char*)malloc(i+2);
		strcpy(str, _str);
		free(_str);
		
		str[i++] = '0';
	}
	str[i] = '\0';
	
	
	_str = (char*)malloc(i);
	strcpy(_str, str);
	
	for(i=0; i<strlen(str); i++)
		str[i] = _str[strlen(str)-i-1];
	str[i] = '\0';
	
	free(_str);
	return str;
}

