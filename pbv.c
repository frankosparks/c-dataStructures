#include <stdio.h>
//function to pass by value
void passbyvalue(int x){
  x=20;
  printf("Inside pass by value x=%d\n",x);
}

int main(){
  int a=5;
  printf("Before passing by value a=%d\n",a);
  passbyvalue(a);
  printf("After passing by value a=%d\n",a);
}