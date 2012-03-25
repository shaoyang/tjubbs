#include<stdio.h>
#include<stdlib.h>

#define PATH "/home/villasy/src/tjubbs/collect"
int main(){
   FILE* fp = NULL;
   /*
      if(access(PATH,0) != -1){
   //file exsits
   fp = fopen(PATH,"a");
   printf("file exsits");
   }else{
   //file not exsit
   fp = fopen(PATH,"a");
   printf("create file");
   }
    */
    fp = fopen(PATH,"a");

}
