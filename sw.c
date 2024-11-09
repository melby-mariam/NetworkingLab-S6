#include<stdio.h>
#include<stdlib.h>

int ak,k,p,disconnect=0,errorack=1;
char turn='s';

void sender() {
	static int flag=0;
	if(turn=='s'){
		if(errorack==0){
			printf("SENDER:Resent packet with seq no.%d\n",p);
			turn='r';
		}
		else {
		if(flag==1) 
			printf("SENDER:Received ACK for packet %d\n\n",ak);
		if(p==5){
			disconnect=1;
			flag=1;
		}
		
			p++;
			printf("SENDER:Sent packet with seq no.%d\n",p);
			turn='r';
			flag=1;
		}
	}
}

void receiver() {
	static int frexp=1;
	if(turn=='r') {
		errorack=rand()%2;
		if(errorack==0)
			printf("An error has occured\n");
		else {
			if(p==frexp) {
				printf("RECEIVER:Received packet with seq no.%d\n",p);
				ak=p;
				frexp++;
				turn='s';
			}
			else {
				printf("RECEIVER:Received duplicate packet %d\n",frexp-1);
				printf("RECEIVER: Previously received packet %d discarded\n",frexp-1);
				ak=frexp-1;
				turn='s';
			}
			errorack=rand()%2;
			if(errorack==0)
				printf("RECEIVER:Error while sending ACK\n");
			}
		}
	}
void main() {
	p=0;
	
	while(!disconnect) {
	sender();
	for(k=0;k<=100000000;k++);
	receiver();
	}
}
	 
	
