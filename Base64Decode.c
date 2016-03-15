#include <stdio.h>
#include <ctype.h>
#include <string.h>
int bdecode(int c){//decode from ASCII to 4 bytes base64 using base64 encoding table
    if (c>=65&&c<=90) {
        return c-65;
    }
    if (c>=97&&c<=122) {
        return c-97+26;
    }
    if (c>=48&&c<=57) {
        return c-48+52;
    }
    if (c==43) {
        return 62;
    }
    if (c==47) {
        return 63;
    }
    else{
        return -1;
    }
}

void Base64Decode(FILE *file){//base64 decode function to decode every 4 character to 3 character
    FILE *f=file;
    int c;
    char a;
    int num[3];
    long i=0;
    int temp;
    int b;
    int j=0;
    while ((c=fgetc(f))!=EOF) {
//        if (c==10||c==61||c==13) {
//            continue;
//        }
        a=c;
        if (a=='\n') {//ignore <ENTER>
            continue;
        }
        if (a=='=') {//facing = to end decoding
            break;
        }
        b=bdecode(c);
        if (b==-1) {
            printf("invaild input data\n");
            return;
        }
        if (i%4==0) {
            temp=b;
        }
        if (i%4==1) {
            num[0]=temp*4+(b>>4);
            temp=b-(b>>4)*16;
            fputc(num[0],stdout);
            
            
            j++;
        }
        if (i%4==2) {
            num[1]=(b>>2)+temp*16;
            temp=b-(b>>2)*4;
            fputc(num[1],stdout);
            
            
            j++;
        }
        if (i%4==3) {
            num[2]=b+temp*64;
            fputc(num[2],stdout);
            
            
            j++;
        }
        
        //        if (j==64) {
        //            printf("\n");
        //            j=0;
        //        }
        
        i++;
        
        
    }
    if (i%4!=0&&a!='=') {// if exit unexpexted then stderr error message
        fprintf(stderr,"invalid input data\n");
    }
//    printf("\n");
}
