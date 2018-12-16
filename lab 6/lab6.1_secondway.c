#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define size 20971520

int main(){
        static char buffer[size];
        int i;
        
        for( i=0; i<size; i++ )
                buffer[i]='A'+i%26;
                
        int fid=open("output",O_WRONLY|O_CREAT);
        if(fid<0)
                return 0;
                
        write(fid,buffer,size);
        close(fid);
        return 0;
}

