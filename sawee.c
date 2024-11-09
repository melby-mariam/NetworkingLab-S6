#include <stdio.h>
#include <stdlib.h>
int ak,k,p,disconnect=0,errorack=1;
char turn = 's';
void sender(){
static int flag = 0;
if(turn == 's'){
if(errorack == 0){
printf("SENDER: Resent packet with seq NO: %d\n",p);
turn='r';
}else{
if(flag == 1)
printf("SENDER: Recieved ACK for packet %d\n\n",ak);
if(p==5){
disconnect = 1;
return;
}
p++;
printf("SENDER: sent packet with Seq no. %d\n",p);
turn='r';
flag=1;
}
}
}
void reciever(){
static int frexp = 1;
if(turn=='r'){
errorack = rand() %2;
if(errorack==0)
printf("An error has occured\n");
else{
if(p == frexp){

printf("RECEIVER: Recieved packet withseq %d\n",p);
ak = p;
frexp++;
turn='s';
}else{
printf("RECIEVER: Recieved duplicate packet %d\n",frexp-1);
printf("RECIEVER: Previously recieved packet %d discarded\n",frexp-1);
ak = frexp-1;
turn ='s';
}
errorack = rand() %2;
if(errorack==0)
printf("Error while sending ACK\n");
}
}
}
void main(){
p = 0;
while(!disconnect){
sender();
for(k=1;k<=1000000000;k++);
reciever();
}
}
