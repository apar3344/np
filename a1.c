#include<stdio.h>                                                                                                                                          
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define N strlen(g)

char t[120],cs[120],g[]="100000111";
int a,c,e;

void xor()
{
 for(c=1;c<N;c++)
 cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc()
{
    int i, j;

    for (i = 0; i < N; i++){
        cs[i] = t[i];
    }

    for (j = 0; j <= a-1; j++){

        if (cs[0] == '1'){
            xor();
        }
        
        for (i = 0; i < N-1; i++){
            cs[i] = cs[i+1];
        }

        cs[N-1] = t[j+N];
    }
}



void main()
{
printf("enter the polynomial\n");
scanf("%s",t);
printf("generating polynomial is %s\n",g);
a=strlen(t);
for(e=a;e<a+N-1;e++)
t[e]='0';
printf("modified t[u] is %s\n",t);
crc();
printf("checksum is :%s\n",cs);
for(e=a;e<a+N-1;e++)
t[e]=cs[e-a];
printf("final codeword is :%s\n",t);
printf("test error detection 0(yes)1(no)?:\n");
scanf("%d",&e);
if(e==0)
 {
 do
  {
   printf("enter position where error has to be inserted\n");
   scanf("%d",&e);
  }
while(e==0 || e>a+N-1);

 t[e-1]=(t[e-1]=='0')?'1':'0';
 printf("errorneous data %s\n",t);
}

crc();

for(e=0;(e<N-1)&&(cs[e]!='1');e++);
 if(e<N-1)
  printf("error detected\n");
 else
  printf("error is not detected\n");
}
