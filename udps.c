#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main(int argc,char* argv[])
{
	struct sockaddr_in server,client;
	if(argc!=2)
	printf("input format not correct");
	
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	printf("Error in socket()\n");
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(atoi(argv[1]));
	
	if(bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
	printf("Error in sockfd()!\n");
	
	char buffer[100];
	socklen_t server_len=sizeof(server);
	printf("server waiting...\n");
	
	if(recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server,&server_len)<0)
	printf("Error in recvfrom()!\n");
	
	printf("Got a datagram:%s",buffer);
	return 0;
}
	
