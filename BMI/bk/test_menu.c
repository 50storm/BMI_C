#include <stdio.h>

enum menu {REGISTER = 1 , DISPLAY = 2, EXIT = 9  };


int show_menu(){
    int  i_menu;
    char c_menu;

    while(1){
        printf("======================================\n");
        printf("   Register BMI DATA(presskey:r)      \n");
        printf("   Disply BMI DATA(presskey:d)        \n");
        printf("   Exit(presskey:e)                   \n");
        printf("======================================\n");
        printf("===>>:");
        scanf("%d",&i_menu);
        c_menu = getchar();
        if( c_menu == 'a'){
            i_menu = REGISTER;
            break;
        }else if(c_menu == 'b'){
            i_menu = DISPLAY;
            break;
        }else if(c_menu =='e' ){
            i_menu = EXIT;
            break;
        }

    }
    return i_menu;
     
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
