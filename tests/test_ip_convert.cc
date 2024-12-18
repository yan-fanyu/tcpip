#include<arpa/inet.h>
#include<stdio.h>

int main(){
	char* szValue = inet_ntoa("1.2.3.4");
	printf("%s\n", szValue);
	
	return 0;
}
