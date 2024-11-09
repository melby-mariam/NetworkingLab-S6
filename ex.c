#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	printf("\nFF\nPID=%d",getpid());
	
	char* args={"Hello","ss","fff",NULL};
	execv("./f2",args);
	printf("Back to f1.c");
	return 0;}
	

