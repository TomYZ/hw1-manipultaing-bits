#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include "hexdump.c"
#include "Base64Encode.c"
#include "Base64Decode.c"

int main(int argc,char * argv[]){
    FILE *f;
    extern int errno;
    FILE *temp;
    if (argc!=2&&argc!=3) {
        printf("malformed command\n");// invalid command if the argc number is not right
        return 0;
    }
    if (argc>=3) {
        
        if (strcmp(*(argv+1),"hexdump")==0) {// if input 3 argc and input hexdump, then choose to hexdump file
            f=fopen(*(argv+2),"rb");
            if (f==NULL) {
                char * mesg=strerror(errno);
                fprintf(stderr,"%s\n",mesg);// if cannot open file, stderr error message
                return 0;
            }
            hexdump(f);
        }
        else if (strcmp(*(argv+1),"enc-base64")==0) {// if input 3 argc and input enc-base64, then choose to encode base64 file
            f=fopen(*(argv+2),"rb");
            if (f==NULL) {
                char * mesg=strerror(errno);
                fprintf(stderr,"%s\n",mesg);
                return 0;
            }
            Base64Encode(f);
        }
        else if (strcmp(*(argv+1),"dec-base64")==0) {// if input 3 argc and input dec-base64, then choose to decode base64 file
            f=fopen(*(argv+2),"r");
            if (f==NULL) {
                char * mesg=strerror(errno);
                fprintf(stderr,"%s\n",mesg);
                return 0;
            }
//            struct stat file;
//            stat(*(argv+2),&file);
//            if (file.st_size%4!=0) {
//                fprintf(stderr,"invalid input data\n");
//                return 0;
//            }
            Base64Decode(f);
        }
        else{
            fprintf(stderr,"malformed command\n");// if do not choos any command, then stderr erro message.
        }
    }
    else{
        if (strcmp(*(argv+1),"hexdump")==0) {// if input 2 argc and input hexdump, then choose to hexdump sdtin
            hexdump(stdin);
        }
        else if (strcmp(*(argv+1),"enc-base64")==0) {// if input 2 argc and input enc-base64, then choose to encode base64 stdin
            Base64Encode(stdin);
        }
        else if (strcmp(*(argv+1),"dec-base64")==0) {// if input 2 argc and input dec-base64, then choose to decode base64 stdin
            Base64Decode(stdin);
        }
        else{
            fprintf(stderr,"malformed command\n");
        }
    }
    
    
    
//    scanf("%x",&c);
//    f=fopen("temp","wb");
//    fwrite(&c,sizeof(char),1,f);
//    f=fopen("temp","rb");
    
    
    return 0;
}
