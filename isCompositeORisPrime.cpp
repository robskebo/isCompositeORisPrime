// isCompositeORisPrime.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

int main() 
{

  int n, i, c = 0;

  printf("Enter any number n:");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) 
  {
      if (n % i == 0) 
	  {
         c++;
      }
  }
  if (c == 2) 
  {
  	printf("n is a Prime number");
	printf("\n");
  }
  else {
 	 printf("n is a Composite number");
	 printf("\n");
  }
  return 0;    
}  
