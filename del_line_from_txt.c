#include<stdio.h> 

void main(){
	FILE *fin;
	fpos_t pos_w,pos_r,pos;
	int i,k,L=3;
	char *one_line;

	one_line = (char *) malloc(1000*sizeof(char));

	fin = fopen ("a.txt","rb+");
	for (i=1;i<L;i++) 
		fgets(one_line,999,fin);

	fgetpos (fin,&pos_w);
	fgets(one_line,999,fin); // delete
	fgetpos (fin,&pos_r);
	pos = pos_r;

	while (1 == 1){
		fsetpos (fin,&pos);
		if (fgets(one_line,999,fin) ==NULL) 
			break;
		fgetpos (fin,&pos_r);
		pos = pos_w;
		fsetpos (fin,&pos);
		fprintf(fin,"%s",one_line);
		fgetpos (fin,&pos_w);
		pos = pos_r;
	}
	pos = pos_w;
	fsetpos (fin,&pos);
	k = strlen(one_line);
	for (i=0;i<k;i++) 
		fputc(0x20,fin);
	fclose(fin);
}
