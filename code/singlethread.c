// C program for single thread matrix multiplication
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>

# define MAT_DIM 1000

int main (void) {
	// Variables
	unsigned short mat[MAT_DIM][MAT_DIM], res[MAT_DIM][MAT_DIM], i, j, k;
	
	// Clock
	clock_t start, end;
    double cpu_time_used;
	
	// Starting clock
	start = clock();

	//Generate random matrix
	srand(time(0));
	for ( i = 0; i < MAT_DIM; i++ ) 
		for ( j = 0; j < MAT_DIM; j++ )
		{	
			res[i][j] = 0;
			mat[i][j] = rand() % USHRT_MAX;
		}
	
	//Matrix multiplication algorithm
	for ( i = 0; i < MAT_DIM; i++ ) 
		for ( j = 0; j < MAT_DIM; j++ )
			for ( k = 0; k < MAT_DIM; k++ )
				res[i][j] += mat[i][k] * mat[k][j];
	
	// Ending clock
	end = clock();
     	
	// Run time calculation
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	// Print result
	printf("Matrix dimensions %d\n", MAT_DIM);
	printf("Run time : %f s\n", cpu_time_used);

	return 0;
}
