#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int is_prime(unsigned long long);
void pf(unsigned long long);

int main(int argc, char *argv[ ])
{
    int j = atoi(argv[1]);
    unsigned long long int x, a = 0;
    unsigned long long int y = 1;

    for(int i=0;i<j;i++)
    {
	a = x + y; 
        if(is_prime(y)) printf("%d: %llu\n", i+1, y);
        else
	{
		printf("%d: %llu (", i+1, y);
		pf(y);
		printf("\b)\n");
	}
	if( x > ULONG_MAX - y ) break;
	x = y;
	y = a;
    }		 

    return 0;
}

int is_prime(unsigned long long num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}

void pf(unsigned long long n)      
{ 
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }

    if (n > 2)
        printf ("%llu ", n);
}
