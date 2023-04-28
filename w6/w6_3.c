#include<stdio.h>

int str_len(char* s){
	int len=0;
	while(s[len]!='\0')
		len++;
	return len;
}

char* str_cat(char* s1, char* s2){
	s1+=str_len(s1);
	while(s2!='\0'){
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return s1;
}

char* str_cpy(char* dest, char* origin){
	while(*origin!='\0'){
		*dest = *origin;
		dest++;
		origin++;
	}
	*dest='\0';
	return dest;
}

int str_cmp(char* s1, char* s2){
	while(1){
		if(*s1>*s2)
			return 1;
		else if(*s1<*s2)
			return -1;
		s1++;
		s2++;
		if(*s1=='\0' && *s2=='\0')
			return 0;
		else if(*s1=='\0')
			return -1;
		else if(*s2=='\0')
			return 1;
	}
}

void main(void){
	char s1[100] = "Hello";
	char s2[100] = " World!";
	printf("strlen(s1) = %d\n",str_len(s1));
	str_cat(s1, s2);
	printf("strcat(s1, s2) = %s\n", s1);
	str_cpy(s2, "Hell");
	printf("strcpy(s2, \"Hell\") = %s\n", s2);
	printf("strcmp(s1, s2) = %d\n", str_cmp(s1, s2));
}
