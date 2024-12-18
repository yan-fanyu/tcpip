#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>

static bool stop = false;

static void handle_term(int sig){
	stop = true;
}

int func(){
	int argc = 4;
	signal(SIGTERM, handle_term);
	
	if(argc <= 3){
		printf("%s \n", basename("test_socket"));
		return 1;
	}
	
	const char * ip = "127.0.0.1";

		

	int port = atoi("12345");
	int backlog = atoi("5");

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	assert(sock >= 0);

	// 创建一个 IPv4 socket 地址
	struct sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);
	
	int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);

	ret = listen(sock, backlog);
	assert(ret != -1);
	
	/*循环等待连接 直到有 SIGTERM 信号将它中断*/
	while(!stop){
		sleep(1);
	}

	/*关闭 socket */
	close(sock);
	

	return 0;
}


int main(){
	int n = 4;
	func();
	return 0;

}
