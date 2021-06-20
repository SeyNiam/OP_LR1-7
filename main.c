#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#endif

#include <stdio.h>
#include <stdlib.h> //contains functions for memory allocation, control of the program execution process, type conversion, etc.

int main() {
	int endFlag = 1; //a flag that stops the application
	//a global cycle that prevents the program from ending without the users desire
	do {
		long int N; //the number to be operated on
		unsigned long int mask = 0xaaaaaaaa; //mask of all odd bits
		unsigned long int mask2 = 0x55555555; //mask of all even bits
		int tmp, tmp2;

		//prompt for user input
		printf("Please input N in hex format: ");
		scanf("%lx", &N);

		//output in binary for clarity
		printf("\nYour number in binary : ");
		for (int i = CHAR_BIT * sizeof(long) - 1; i >= 0 ; i--)
			printf("%d", (N & (1 << i)) ? 1 : 0);

		tmp = N & mask; //extracting odd bits
		tmp = tmp >> 1; //offset odd to the left
		tmp2 = N & mask2; //extracting even bits
		tmp2 = tmp2 << 1; //offset even to the right

		N = tmp | tmp2; //combining the results of offsets
		printf("\nYour number in binary : ");
		for (int i = CHAR_BIT * sizeof(long) - 1; i >= 0; i--)
			printf("%d", (N & (1 << i)) ? 1 : 0);

		printf("\n\nNew N is: %lx", N);

		//suggesting to user to run program again or exit.
		printf("\n\nPlease choose from the following:\n\t1 - Count again.\n\t2 - Exit.\n");
		scanf("%d", &endFlag);
		switch (endFlag) {
		case 1: endFlag = 1; break;
		case 2: endFlag = 0; break;
		default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
		}
	} while (endFlag); //if flag is 0, then exiting out of cycle 
	return 0;
}
