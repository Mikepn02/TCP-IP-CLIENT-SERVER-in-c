#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
	
	char *ip = "127.0.0.1";
	int port = 5566;
	
	int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	
	//creating socket server to receive incomming requests;
	sock = socket(AF_INET,SOCK_STREAM,0);
	//AF_INET is the address family(IPV4),sock_stream is socket type and 0 is protocal
	if(sock < 0){
		perror("[-]Socket error");
		exit(1);
	}
	printf("[+]TCP server socket created.\n");
	
	//initializing memory block of the server_addr
	memset(&addr,'\0',sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = port;
	addr.sin_addr.s_addr = inet_addr(ip);
	
    //connecting to the server
    
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    printf("connnected to the server.\n");
    
    bzero(buffer,1024);
    strcpy(buffer,"Hello , this is client");
    printf("client: %s\n",buffer);
    send(sock,buffer,strlen(buffer),0);
    
    bzero(buffer,1024);
    recv(sock,buffer,sizeof(buffer),0);
    printf("Server: %s\n",buffer);
    
    close(sock);
    printf("Disconnect fro the server.\n");
    

	return 0;
}
