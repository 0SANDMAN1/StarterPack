#include<stdio.h>
int main(){
   int number,remainder,total=0,original;

   printf("enter the number=");

   scanf("%d",&number);

   original=number;

   while(number>0){

      remainder=number%10; //extracting the last digit of the number

      total=total+(remainder*remainder*remainder);

      number=number/10; //it removes the last digit and restarts the loop again until it comes to zero
   }

   if(original==total)

      printf("This number is Armstrong number");

   else

      printf("This number is not Armstrong number");

   return 0;
}
