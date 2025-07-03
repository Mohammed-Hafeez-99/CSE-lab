#include <stdio.h>
#include <stdlib.h>

int choice = 0;
int max, top = -1;
int stack[50];

void push() {
  int cat;
  if (top == max - 1) {
    printf("stack overflow\n");
  } else {
    printf("enter the element to be pushed\n");
    scanf("%d", &cat);
    stack[++top] = cat;
  }
}

void display() {
  if (top == -1) {
    printf("stack is empty\n");
  } else {
    for (int i = top; i >= 0; i--) {
      printf("%d\n", stack[i]);
    }
  }
}

void pop() {
  if (top == -1) {
    printf("stack underflow\n");
  } else {
    printf("the element %d was deleted\n", stack[top]);
    top--;
  }
}

void showTop() {
  if (top == -1) {
    printf("stack is empty\n");
  } else {
    printf("the top element is %d\n", stack[top]);
  }
}

int main() {
  printf("enter max\n");
  scanf("%d", &max);

  while (1) {
    printf("       choose a valid option\n");
    printf("1.push\n2.pop\n3.display stack\n4.top\n5.exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      showTop();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
