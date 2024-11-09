#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#define MAX 80
#define PORT 8081
#define SA struct sockaddr

void func(int sockfd){

	char buff[MAX];
	int n;
	for(;;){
		bzero(buff,sizeof(buff));
		printf("Enter the string: ");
		n=0;
		while((buff[n++]=getchar())!='\n');
		write(sockfd,buff,sizeof(buff));
		bzero(buff,sizeof(buff));
		read(sockfd,buff,sizeof(buff));
		printf("From client:%s",buff);
		bzero(buff,sizeof(buff));
		
		if (strncmp(buff,"exit",4)==0){
			printf("Client exit...\n");
			break;
			}
		}
		
	}
	
int main()
{
	int sockfd,connfd;
	struct sockaddr_in servaddr,cli;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("socket creation failed..\n");
		exit(0);
		}
	else
		printf("socket successfully created...\n");
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);
	
	if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr))!=0){
		printf("connection to server failed..\n");
		exit(0);
	}
	else
		printf("Server connected to client...\n");
	
		
	func(sockfd);
	close(sockfd);
}
	

