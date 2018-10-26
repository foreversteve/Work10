#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int gen_rand(){
	int filedesc = open("/dev/random", O_RDONLY);
	int out[1];
	if(read(filedesc, out, 4) < 4){
		exit(0);
	}
	close(filedesc);
	return out[0];
}
int main(){
	printf("\nGenerating Random Numbers:\n");
	int arr[10];
	for (int i = 0; i < 10; i++){
		arr[i] = gen_rand();
		printf("Random number %d: %d\n",i,arr[i]);
	}

	int filedesc = open("file.txt", O_WRONLY);
	printf("\nWriting numbers to file.txt...\n");
	if (write(filedesc, arr, 40) != 40){
		printf("Error writing to file\n");
		exit(0);
	}

	printf("\nReading numbers from file.txt...\n");
	int arr1[10];
	int filedesc1 = open("file.txt", O_RDONLY);
	if (read(filedesc1, arr1, 40) != 40){
		printf("Error reading file\n");
		exit(0);
	}

	printf("\nVerification that written values were the same:\n");
	for (int i = 0; i < 10; i++){
		arr[i] = gen_rand();
		printf("Random number %d: %d\n",i,arr[i]);
	}
	printf("\n");
	return 0;
}




