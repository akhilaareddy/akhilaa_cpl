#include<stdio.h>

int compar ( const void *p1, const void * p2 )
{
	return *p1 - *p2;
}

void swap ( void *b, int i, int j, int size )
{
	void *temp;
	
	temp =  base+j*size;
	base+j*size = base+(j+1)*size;
	base+(j+1)*size=base+j*size;
}
void bsort ( void *base, int num, int size, int (*compar) (const void*, const void * ))
{
	int i, j;
	
	for ( i = 0 ; i < num - 1 ; i++ )
	{
		for ( j = 0 ; j < num - 1 - i ; j++ )
		{
			if ( (*compar) ( base+j*size, base+(j+1)*size ) > 0 )
				swap (  base+j*size, base+(j+1)*size, size );
		}
	}
}

int main()
{
	int n, a [ 10 ], i;
	
	printf ( "\nEnter the number of elements: " );
	scanf( "%d", &n );
	
	printf ( "\nEnter the elements: " );
	for ( i = 0 ; i < n ; i++ )
		scanf ( "%d", &a [ i ] );
		
	bsort ( a, n, sizeof(int), compar ); 
}
