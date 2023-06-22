#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void runAgain();

void swap(long int *a, long int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(long int a[], long int n)
{
	for (long int i = 0; i < n - 1; i++) 
	{
		for (long int j = 0; j < n - 1 - i; j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

void bubbleSortNormal(long int a[], long int n)
{
	for(long int i = 1; i < n; i++)
	{
		for(long int j = 0; j < n - i ; j++)
		{
			if(a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void sortTimer(long int n)
{
	int it = 0;
	double tim1[10], tim2[10];
	long int a[n], b[n];
	
	for (int i = 0; i < n; i++) 
	{
		long int no = rand() % n + 1;
		a[i] = no;
		b[i] = no;
	}
	
	clock_t start, end;

	start = clock();
	bubbleSortNormal(a, n);
	end = clock();

	tim1[it] = ((double)(end - start)) / CLOCKS_PER_SEC;

	start = clock();
	bubbleSort(b, n);
	end = clock();

	tim2[it] = ((double)(end - start)) / CLOCKS_PER_SEC;


	printf("%li\t,    %li\t   ,     %li\t,",
		n,
		(long int)tim1[it],
		(long int)tim2[it]);
		
	printf("   %6.3f  ,   %6.3f\n",
		tim1[it],
		tim2[it]);
}

int main()
{
	long int n1 = 1000, n2 = 16000, n3 = 64000;

	printf("Arr_size, Bubble(s), Bubble_P(s), Bubble(ms), Bubble_P(ms)\n");

	sortTimer(n1);
	sortTimer(n2);
	sortTimer(n3);
	
	runAgain();
	
	return 0;
}

void runAgain()
{
	char c, s[1];
		
	printf("\nJalankan lagi? (y/n)");
	fgets(s, 2, stdin);
	sscanf(s, "%c", &c);
	printf("\n");
	fflush(stdin);
	
	for(;;)
	{
		switch(c) 
		{
			case 'y' :
			case 'Y' :
			{ 	
				main();
			}
			case 'n' :
			case 'N' :
			{
				printf("Program Selesai!");
				exit(0);
			}
			default :
			{
				printf("Pilihan Salah!\n");
				runAgain();
			}
		}
	}
}

