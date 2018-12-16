#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

        FILE* fid=fopen("output","w");
        if(!fid)
                return 1;
        int size=20971520;
        int i;
        for( i=0; i<size; i++){
                char c='A'+i%26;
                fprintf(fid,"%c",c);
        }
        fclose(fid);
        return 0;
}


