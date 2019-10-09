#include <stdio.h>
typedef unsigned char byte;

int main(){
	FILE *f1,*f2;
    byte temp;     
	f1=fopen("eece.jfif","rb");
	f2=fopen("new.jfif","wb");
	while(1){
	   fread(&temp,1,1,f1);		
	   if (feof(f1)) { 
	     break;
       }		 
	   fwrite(&temp,1,1,f2);	
	}
	fclose(f1);
	fclose(f2);
	return 0;
}