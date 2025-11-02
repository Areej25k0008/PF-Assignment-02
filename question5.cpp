#include <stdio.h>
#include <string.h>
void encodeMessage(char message[])
{
    int i,len;
    char temp;
    len=strlen(message);
    for(i=0;i<len/2;i++)
    {
        temp=message[i];
        message[i]=message[len-i-1];
        message[len-i-1]=temp;
    }
    for(i=0;i<len;i++)
    {
        message[i]=message[i]^(1<<1); 
        message[i]=message[i]^(1<<4); 
    }
    printf("\nEncoded Message: %s\n",message);
}
void decodeMessage(char message[])
{
    int i,len;
    char temp;
    len=strlen(message);
    for(i=0;i<len;i++)
    {
        message[i]=message[i]^(1<<1);
        message[i]=message[i]^(1<<4);
    }
    for(i=0;i<len/2;i++)
    {
        temp=message[i];
        message[i]=message[len-i-1];
        message[len-i-1]=temp;
    }
    printf("\nDecoded message: %s\n",message);
}
int main()
{
    char message[200];
    int choice;
    while(1)
    {
        printf("\n--- TCS Message Security Tool ---\n");
        printf("1. Encode message\n");
        printf("2. Decode Message\n");
        printf("3. exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        getchar(); 
        if(choice==1)
        {
            printf("Enter message to encode:");
            fgets(message,sizeof(message),stdin);
            message[strcspn(message,"\n")]=0;
            encodeMessage(message);
        }
        else if(choice==2)
        {
            printf("Enter message to decode: ");
            fgets(message,sizeof(message),stdin);
            message[strcspn(message,"\n")]=0;
            decodeMessage(message);
        }
        else if(choice==3)
        {
            printf("Exiting program...\n");
            break;
        }
        else
        {
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

