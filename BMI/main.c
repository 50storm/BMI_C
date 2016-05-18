//
//  main.c
//  BMI
//
//  Created by 五十嵐博司 on 2016/05/18.
//  Copyright © 2016年 五十嵐博司. All rights reserved.
//

#include <stdio.h>
#define true 1
#define false 0


int main(int argc, const char * argv[]) {
    int fat, thin, normal;
    double h,w,bmi;
    
    int flg_h=1;
    while (flg_h) {
        printf("Please input your hight (cm):");
        scanf("%lf",&h );
        
        if(h<=0){
            printf("Wrong input for height(cm):");
            flg_h=1;
            
        }else{
            flg_h=0;
            
        }
        
    }
    
    return 0;
    
    while (is_weghit_ok == 0) {
        printf("Please input your weight (cm):");
        scanf("%lf",&w );
        if(w <= 0) {
        }else{
        }
        
   } 
    
    
    
    bmi = w*10000/(h*h);
    fat = (bmi>25.0);
    thin = (bmi<=18.5);
    normal = (!fat) && (!thin);
    
    printf("BMI=%4.1f FAT:%d NORMANL:%d THIN:%d\n", bmi, fat, normal, thin);
    
    if(fat) printf("You are fat\n");
    else if(thin) printf("You are thin\n");
    else printf("You are normal\n");	
    

    return 0;
}
