#include <stdio.h> 


void print_pascal_triangle_array(int size ,int array[size][size]){

	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<i+1 ; j++){
			printf(" %3d ", array[i][j]);
		}
	printf("\n");
	}
}

void creat_pascal_triangle(int size , int array[size][size]){

	for(int i=0 ; i<size ; i++){
		array[i][0]=1;
	}

	for(int i=1 ; i<size ; i++){
		for(int j=1 ; j<i+1 ; j++){
			array[i][j]= array[i-1][j-1] + array[i-1][j];
		}
	}
}

void print_pascal_triangle_pointer(int size , int *array){

	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<i+1 ; j++){
			printf(" %3d ", *(array+(10*i)+j));
		}
	printf("\n");
	}

	
}