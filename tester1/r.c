#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	print_arr(int *arr, int size){
	for (int i = 0; i < size; i ++)
		printf("%d ", arr[i]);
}

void	shuffle(int *arr, int num){
	int temp;
	int r;

	srand(time(NULL));
	for (int i = 0; i < num - 1; i ++){
		r = rand() % (num - i) + i;
		temp = arr[i];
		arr[i] = arr[r];
		arr[r] = temp;
	}
	
}

int main(int argc, char *argv[]){

	if (argc < 2)
		return (printf("too few arguments\n"));
	else if (argc > 2)
		return (printf("too many arguments\n"));
	
	int size = atoi(argv[1]);
	int arr[size];
	
	for (int i = 0; i < size; i ++)
		arr[i] = i + 1;
	shuffle(arr, size);
	print_arr(arr, size);
}