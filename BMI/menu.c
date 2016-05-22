#include <stdio.h>

enum menu {REGISTER = 1 , DISPLAY = 2, EXIT = 9, ERR = -1  };


int show_menu(){
    int i_menu;

    printf("======================================\n");
    printf("   Register BMI DATA(presskey:1)      \n");
    printf("   Disply BMI DATA(presskey:2)        \n");
    printf("   Exit(presskey:9)                   \n");
    printf("======================================\n");
    printf("===>>:");
    scanf("%d",&i_menu);
    if( i_menu == REGISTER || i_menu==DISPLAY || i_menu == EXIT ){
        return i_menu;
    }else {
        //   printf("Please select 1 or 2 or9 \n");
        return -1;
    }
     
}
int main(){

   int i_menu;
   i_menu = show_menu();

    switch(i_menu){
    case REGISTER:
	printf("Register\n");
    break;

    case DISPLAY:
	printf("Display\n");
    break;
    }
    return 0;

}
