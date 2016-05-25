#include <stdio.h>
#include <string.h>


int main(){
//	char str[]="bmi=50.6";
   	char str[] = "BMI=27.8 FAT=1 NORMANL=0 THIN=0 POO=1   STEPS=1900 ";
   	puts(str);
   	char *bmi, *poo, *steps;

//	char str[]="ABC.123.CDE.456";
        char *tp;
        tp = strtok(str , "=");
//        puts( tp);
        printf("%s\n",tp);

	while( tp != NULL ){
		tp = strtok( NULL, "=");
		if(tp != NULL) 
		//puts( tp );
			printf("%s\n",tp);

        }
	return 0;

}
