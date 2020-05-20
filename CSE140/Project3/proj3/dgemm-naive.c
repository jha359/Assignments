void dgemm( int m, int n, float *A, float *C )
{
  for( int i = 0; i < m; i++ )
    for( int k = 0; k < n; k++ ) 
      for( int j = 0; j < m; j++ ) 
	C[i+j*m] += A[i+k*m] * A[j+k*m];
}

/*void dgemm( int m, int n, float *A, float *C ) //Unrolling
{
    int f = m % 3;
    for( int i = 0; i < m; i++)
    {
        for( int k = 0; k < n; k++)
        {
            int j;
            for(j = 2; j < m; j+=3)
            {
	            C[i + j * m] += A[i + k * m] * A[j + k * m];
	            C[i + (j-1) * m] += A[i + k * m] * A[(j-1) + k * m];
	            C[i + (j-2) * m] += A[i + k * m] * A[(j-2) + k * m];
            }
            if(f == 2)
            {
                C[i + (j-2) * m] += A[i + k * m] * A[(j-2) + k * m];
                C[i + (j-1) * m] += A[i + k * m] * A[(j-1) + k * m];
            }
            else if(f == 1)
            {
                C[i + (j-2) * m] += A[i + k * m] * A[(j-2) + k * m];
            }
        }
    }
}*/