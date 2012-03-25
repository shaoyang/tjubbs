#include<stdio.h>
#include<stdlib.h>

#define PATH  "/home/villasy/src/tjubbs/collect"
#define board "notepad"
int main(){
    char line[200],collect[6][80],buf[80];
    int i,j,k,n,file = 1322906124,total=0,pos=0;
    FILE *fp = NULL;
    /*
    fp = fopen(PATH,"r+");
    if(!fseek(fp,10,SEEK_SET)){
        fputs(" sam",fp);
    }else{
        printf("seek\n");
    }
    fclose(fp);
    return 0;
    */
    if(fp = fopen(PATH,"r+")){
        while(fgets(line,sizeof(line),fp)){
            line[strlen(line)-1] = '\0';
            k = j = i = n = 0;
            memset(collect,0,sizeof(collect));
            for(;i <= strlen(line);i++){
                if(line[i] == ',' || line[i] == '\0'){
                    for(k = 0; k < i-j; k++){
                        collect[n][k] = line[j + k];
                    }
                    j = i + 1;
                    n++;
                }
            }
            //printf("%d %d\n",atoi(collect[0] + 2),file);
            if(atoi(collect[0]+2) == file && !strcmp(collect[1],board)){
                for(pos = 0,k = 0; k < 5;k++){
                    pos +=  strlen(collect[k]);
                    pos++;
                }
                printf("%d\n",total+pos);
                if(!fseek(fp,total+pos,SEEK_SET)){
                    fputs("0",fp);
                    fclose(fp);
                    return 0;
                }
            }
            total += strlen(line) + 1;
        }
    }
    fclose(fp);
    return -1;
}
