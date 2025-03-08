#include <stdio.h>

int main() {
  int o = 0;
  int max, top = -1;
  int stack[50];
  printf("choose a valid option");
  printf("\n1.push\n2.pop\n3.display stack\n4.top\n5.exit\n");

  switch (o) {
  case 1:
    push();
    break;
  case 2:
   break;
  case 3:
    display() break;
  case 4:
    exit(1);
    break;
  case 0:
    printf("sorry cant do");
    break;
    default printf("why?")
  }
}

push() {
  int cat;
  if (top == max - 1) {
    printf("stack overflow");
  } else {
    printf("enter the element to be pushed") top++;
    scanf("%d", cat);
    top = man;
  }
}
display() {
  if (top == -1) {
    printf("stack is wmpty");}

    else {
      for (int i = 0;i<= max;i--) {
        printf(%d\n, i); 
      }
    }
  }