#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	printf("We are in f2");
	printf("Seconf\nPID=%d\n",getpid());
	return 0;
}
