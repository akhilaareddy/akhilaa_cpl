#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compar ( const void *p1, const void *p2 )
{
	return strcmp ( *(char**)p1, *(char**)p2 );
}

void swap ( void *a , void *b, int size, void *temp )
{
	memcpy ( temp, a, size );
	memcpy ( a, b, size );
	memcpy ( b, temp, size );
}

void bsort ( void *base, int num, int size, int (*compar) ( const void*, const void* ) )
{
	int i, j;
	void *temp;

	temp=malloc(size);	

	for ( i = 0 ; i < num ; i++ )
	{
		for ( j = 0 ; j < num - 1 - i ; j++ )
		{
			if ( compar ( (char*)base+j*size, (char*)base+(j+1)*size ) > 0 )
				swap (  (char*)base+j*size, (char*)base+(j+1)*size, size, temp );
		}
	}

	free ( temp );
}

int main()
{
	int n, i, l;
	char str [ 1000 ];
	char **s;

	printf ( "\nEnter the number of elements: " );
	scanf( "%d", &n );

	s = malloc ( sizeof ( char * ) * n );

	printf("\nEnter the elements: " );
	for ( i = 0 ; i < n ; i++ )
	{
		scanf ( "%s", str );
		l = strlen ( str );
		s [ i ] = malloc ( sizeof ( char ) * (l+1) );
		strcpy ( s [ i ], str );
	}

	printf("\nEnterered elements are: " );
	for ( i = 0 ; i < n ; i++ )
		printf ( "%s\t", s [ i ] );
	printf ( "\n" );

	bsort ( s, n, sizeof ( s[0] ), compar ) ;
	/*qsort ( s, n, sizeof ( char * ), compar ) ;*/

	printf ( "\nThe sorted strings are: " );
	for ( i = 0 ; i < n ; i++ )
		printf ( "%s\t", s [ i ] );
	printf ( "\n" );

	return 0;	
}

