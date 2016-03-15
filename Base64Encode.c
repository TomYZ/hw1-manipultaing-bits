#include <stdio.h>
#include <ctype.h>
#include <string.h>
void bprint(int value){// encode to ASCII using base64 encoding table
    char c;
    if (value>=0&&value<=25) {
        c=value+'A';
    } else if(value>=26&&value<=51){
        c=value-26+'a';
    } else if(value>=52&&value<=61){
        c=value-52+'0';
    } else if(value==62){
        c='+';
    }else {
        c='/';
    }
    printf("%c",c);
}

void Base64Encode(FILE *file){//base 64 encoding function
    FILE *f=file;
    int c;
    int i=0;
    int num[4];
    int temp=0;
    while ((c=fgetc(f))!=EOF) {//encode every 3 character to 4 character
        
        if (i%3==0) {
            num[0]=c/4;
            temp=c-(num[0]*4);
            bprint(num[0]);
        }
        if (i%3==1) {
            num[1]=(temp*16)+(c/16);
            temp=c-(c/16)*16;
            bprint(num[1]);
        }
        if (i%3==2) {
            num[2]=(temp*4)+(c/64);
            num[3]=c-(c/64)*64;
            bprint(num[2]);
            bprint(num[3]);
        }
        if (i%48==47) {
            printf("\n");
            i=-1;
        }
        i++;
        
    }
    if (i%3==1) {// if the total size is not dividable by 4, output = to instead
        bprint(temp*16);
        printf("==");
    }
    if (i%3==2) {
        bprint(temp*4);
        printf("=");
    }
    printf("\n");
}
