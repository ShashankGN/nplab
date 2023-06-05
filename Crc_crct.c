#include<stdio.h>

#include<string.h>

int i,j,dl,gl;

char gen[10];

char data[50];

char check[50];

void xor()

{   for(j=0;j<gl;j++)

     check[j]=((gen[j]==check[j])?'0':'1');

}

void reciver()

{

    for(i=0;i<gl;i++)

        check[i]=data[i];

    do

    {

        if(check[0]=='1')

            xor();

        for(j=0;j<gl-1;j++)

        {

            check[j]=check[j+1];

        }

        check[j]=data[i++];

    

    }while(i<dl+gl-1);

    printf("Crc = %s\n",check);

    int c=0;

    for(i=1;i<gl;i++)

        if(check[i]!='0')

            c=1;

    if(c==1)

        printf("message tampered\n");

    else

        printf("message not tampered\n");

}

void crc()

{

    for(i=0;i<gl;i++)

        check[i]=data[i];

    do

    {

        if(check[0]=='1')

            xor();

        for(j=0;j<gl-1;j++)

        {

            check[j]=check[j+1];

        }

        check[j]=data[i++];

    

    }while(i<dl+gl-1);

    printf("Crc = %s\n",check);

    for(i=1;i<gl;i++)

        data[dl+i-1]=check[i];

    printf("Final= %s\n",data);

}

void main()

{

    

    printf("Enter the message\n");

    scanf("%s",data);

    printf("Enter the genpol\n");

    scanf("%s",gen);

    gl=strlen(gen);

    dl=strlen(data);

    for(i=dl;i<dl+gl-1;i++)

        data[i]='0';

    

    crc();

    reciver();

}
