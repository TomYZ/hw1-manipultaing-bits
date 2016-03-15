#include <stdio.h>
#include <ctype.h>
#include <string.h>
void hexdump(FILE *file){// hexdump function
    FILE *f=file;
    int c;
    long i=0;
    int j=0;
    int k=0;
    char hex[16];
    int array[16];
    while ((c=fgetc(f))!=EOF) {// read a char from file until file ends
        if(i%16==0){
            printf("%0.6lx: ",i);// output address
        }
        //printf("%0.2x ",c);
        array[i%16]=c;
//        if (i%16==7) {
//            printf(" ");
//        }
        if(isprint(c)){
            hex[i%16]=c;
        }
        else{
            if(c>=128){
                hex[i%16]='~';
            }
            else{
                hex[i%16]='.';
            }
        }
        if(i%16==15){// output every 16 bytes
            for (k=0; k<16; k++) {
                printf("%0.2x ",array[k]);//output hexidecimal data
                if (k==7) {
                    printf(" ");
                }
            }
            printf(" ");
            for (j=0; j<16; j++) {
                printf("%c",hex[j]);//output hexdump data
            }
            printf("\n");
            
        }
        i++;
        
    }
    j=i;
    if (j%16!=0) {
        for (k=0; k<j%16; k++) {
            printf("%0.2x ",array[k]);
            if (k==7) {
                printf(" ");
            }
        }
    }
    while (j%16!=0) {
        printf("-- ");
        if (j%16==7) {
            printf(" ");// output the rest data
        }
        j++;
    }
    j=0;
    while (j<(i%16)) {
        
        if(j==0) printf(" ");
        printf("%c",hex[j]);
        j++;
    }
    while (j<16) {
        printf(" ");
        j++;
    }
    printf("\n");
    fclose(f);
}
