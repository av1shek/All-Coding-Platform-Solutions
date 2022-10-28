#include<stdio.h>
#include<conio.h>

void main()
{
  float interest, p, r, n;
  clrscr();

  printf("Enter value of P: ");
  scanf("%f",&p);

  printf("Enter value of R: ");
  scanf("%f",&r);

  printf("Enter value of N: ");
  scanf("%f",&n);

  interest=p*r*n/100f;

  printf("Simple Interest : %f", interest);

  getch();
}
