#include <stdio.h>
struct nums{
int num1,num2,num3;
}s;
int main() {
  printf("Enter three different numbers: ");
  scanf("%d %d %d", &s.num1, &s.num2, &s.num3);
  if (s.num1 >= s.num2 && s.num1 >= s.num3)
    printf("%d is the largest number.", s.num1);
  if (s.num2 >= s.num1 && s.num2 >= s.num3)
    printf("%d is the largest number.", s.num2);
  if (s.num3 >= s.num1 && s.num3 >= s.num2)
    printf("%d is the largest number.", s.num3);

  return 0;
}