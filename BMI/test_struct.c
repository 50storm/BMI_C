#include <stdio.h>

struct bmi_data_type{

   double height;
   double weight;
   double bmi;

};


int main(){

    struct bmi_data_type  bmi_data;
    bmi_data.height = 170.1;
    bmi_data.weight = 65.1;
    printf("height:%f", bmi_data.height);
    printf("weight:%f", bmi_data.weight);

}
