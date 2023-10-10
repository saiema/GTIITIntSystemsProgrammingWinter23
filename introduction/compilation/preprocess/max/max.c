#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

int main(int argc, char ** argv) {
	if (argc != 3) {
		puts("Incorrect amount of arguments\nUsage: ./max <int> <int>");
		return 1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("max(%d, %d): %d\n", a, b, MAX(a, b));
	return 0;
}
