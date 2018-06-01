#include <stdio.h>  
#define LEN     100  

struct _Data_Unit  
{  
  float x;  
  float y;  
};  

struct _Data  
{  
  struct _Data_Unit data[LEN];  
  int len;  
};  

struct _Data Data =   
{  
  .len = 0  
};  

void push(float x,float y)  
{  
  int i = 0;  

  if (Data.len < LEN)  
  {  
    Data.data[Data.len].x = x;  
    Data.data[Data.len++].y = y;  
    return;  
  }  

  for (i = 0;i < LEN - 1;i++)  
  {  
    Data.data[i].x = Data.data[i + 1].x;  
    Data.data[i].y = Data.data[i + 1].y;  
  }  
  Data.data[LEN].x = x;  
  Data.data[LEN].y = y;  
  Data.len = LEN;  
}  

float calc(float x)  
{  
  int i = 0;  
  float mean_x = 0;  
  float mean_y = 0;  
  float num1 = 0;  
  float num2 = 0;  
  float a = 0;  
  float b = 0;  

  for (i = 0;i < Data.len;i++)  
  {  
    mean_x += Data.data[i].x;  
    mean_y += Data.data[i].y;  
  }  
  mean_x /= Data.len;  
  mean_y /= Data.len;  

  printf("mean_x = %f,mean_y = %f\n",mean_x,mean_y);  

  for (i = 0;i < Data.len;i++)  
  {  
    num1 += (Data.data[i].x - mean_x) * (Data.data[i].y - mean_y);  
    num2 += (Data.data[i].x - mean_x) * (Data.data[i].x - mean_x);   
  }  

  b = num1 / num2;  
  a = mean_y - b * mean_x;  

  printf("a = %f,b = %f\n",a,b);  

  return (a + b * x);  
}  


int main()  
{  
  float length[10] = {208,152,113,227,137,238,178,104,191,130};  
  float width[10] = {21.6,15.5,10.4,31.0,13.0,32.4,19.0,10.4,19.0,11.8};  
  int i = 0;  

  for (i = 0;i < 10;i++)  
  {  
    push(length[i],width[i]);  
  }  
  printf("300m长度的战舰预测宽度为为%f米\n",calc(300));  

  getchar();  
  return 0;  
}  

