// C program for multi thread matrix multiplication
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <omp.h>

# define MAT_DIM 10000

// Shared variables
unsigned short mat[MAT_DIM][MAT_DIM], res[MAT_DIM][MAT_DIM];

int main () {
	// Variables
	unsigned short i, j, k; 

	// Setting number of threads
	// omp_set_num_threads(4);

	// Getting number of threads
	printf("Number of threads -> %d\n", omp_get_max_threads());
	
	// Clock
	clock_t start, end;
    double cpu_time_used;
	
	// Starting clock
	start = clock();

	// Matrix initialization
	srand(time(0));
	#pragma omp parallel 
	{
		//printf("Thread %d started\n", omp_get_thread_num());
		#pragma omp for collapse(2)
		for ( i = 0; i < MAT_DIM; i++ ) 
			for ( j = 0; j < MAT_DIM; j++ )
			{	
				res[i][j] = 0;
				mat[i][j] = rand() % USHRT_MAX;
			}
		
		// Matrix multiplication parallel
		#pragma omp for collapse(3)
		for ( i = 0; i < MAT_DIM; i++ )
			for ( j = 0; j < MAT_DIM; j++ )
				for( k = 0; k < MAT_DIM; k++)
					res[i][j] += mat[i][k] * mat[k][j];	
	}

	// Ending clock
	end = clock();
     	
	// Run time calculation
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	// Print result
	printf("Matrix dimensions -> %d\n", MAT_DIM);
	printf("Run time -> %f s\n", cpu_time_used);

	return 0;
}
