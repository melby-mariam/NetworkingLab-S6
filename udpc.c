#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main(int argc,char* argv[])
{
	struct sockaddr_in server,client;
	if(argc!=3)
	printf("input format not correct");
	
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	printf("Error in socket()\n");
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(atoi(argv[2]));
	
	//if(bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
	//printf("Error in sockfd()!\n");
	
	char buffer[100];
	printf("Enter a message to be sent to server\n");
	fgets(buffer,100,stdin);
	
	if (sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(server))<0)
	printf("Error in sendto()!\n");
	return 0;
	
}
	
