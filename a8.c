#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x
int main()
{
	int orate,drop=0,cap,x,count=0,inp[10]={0},i=0,nsec,ch;
	printf("\n enter bucket size : ");
	scanf("%d",&cap);
	printf("\n enter output rate :");
	scanf("%d",&orate);
	do{
	printf("\n enter number of packets coming at second %d :",i+1);
	scanf("%d",&inp[i]);
	if(inp[i]>cap)
	{
		printf("Bucket overflow\n");		
		printf("Packet Discarded\n");
		exit(0);
	}
	i++;
	printf("\n enter 1 to contiue or 0 to quit..........");
	scanf("%d",&ch);
}
while(ch);
nsec=i;
printf("\n Second \t Recieved \t Sent \t Dropped \tRemained \n");

for (i = 0; count || i < nsec; i++)
{
    printf("  %d", i + 1);
    printf(" \t\t%d\t ", inp[i]);
    int sent = MIN((inp[i] + count), orate); // how many packets can be sent
    printf(" \t%d\t ", sent);
    count = inp[i] + count - sent; // update the count for next iteration
    int drop = 0;
    if (count > cap) { // if buffer is full, drop excess packets
        drop = count - cap;
        count = cap;
    }
    printf(" \t %d\t %d \n", drop, count);
}

}