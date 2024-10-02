#include <stdio.h>
//passing by reference
void passbyreference(int *x){
  *x=20;
  printf("inside pass by reference *x =%d\n",*x);
}

int main(){
  int a =25;
  printf("before passing by reference a=%d\n",a);
  passbyreference(&a);
  printf("after passing by reference a=%d\n",a);
}