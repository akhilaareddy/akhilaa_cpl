#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compar ( void *p1, void *p2 )
{
	if(*(int*)p1 > *(int*)p2)
		return 1;

	return 0;

}

int comparstr ( void *p1, void *p2 )
{
	return strcmp ( (char*)p1, (char*)p2 );
}

void swap ( void *a , void *b, int size, void *temp )
{
	memcpy ( temp, a, size );
	memcpy ( a, b, size );
	memcpy ( b, temp, size );
}

void bsort ( void *base, int num, int size, int (*compar) ( void*, void * ))
{
	int i, j;
	void *temp;

	temp=malloc(sizeof(size));	

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
	int n, a [ 10 ], i;
	char s [ 10 ] [ 10 ];
	char **s;
	
	printf ( "\nEnter the number of elements: " );
	scanf( "%d", &n );

	/*printf ( "\nEnter the elements: " );
	for ( i = 0 ; i < n ; i++ )
		scanf ( "%d", &a [ i ] ); */

	printf ( "\nEnter the strings: " );
	  for ( i = 0 ; i < n ; i++ )
	  scanf ( "%s", s [ i ] );

	/*bsort ( a, n, sizeof(int), compar ); */

	bsort ( s, n, sizeof(s[0]),comparstr );

	/*printf ( "\nThe sorted elements are: " );
	for ( i = 0 ; i < n ; i++ )
		printf ( "%d\n", a [ i ] );*/
		
	printf ( "\nThe sorted strings are: " );
	  for ( i = 0 ; i < n ; i++ )
	  printf ( "%s\n", s [ i ] );
}
