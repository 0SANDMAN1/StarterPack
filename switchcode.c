#include <stdio.h>
int main(void)
{
  int RPM;
  printf("Enter Engine RPM\n");
  scanf("%d", &RPM);

  switch(RPM)
  {
  case 180:
    //printf("Attention Needed!\n");
    //break;
  case 200:
    //printf("Critical\n");
    //break;
  case 250:
    //printf("SCRAM NOW\n");
    //break;
    printf("safe");
    break;
  /*default:
    if(RPM<180)
    {
        printf("SAFE\n");
    }*/

  }
    return 0;
}
