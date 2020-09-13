#include<bits/stdc++.h> 
# define U 0.06 
# define V 0.025 
# define M 1.1 
# define N 1.2 
int main(void) { 
    float x, y; 
	float m, n; 
	for ( y=2; y>=-2; y-=U ) { 
	   for ( x=-1.2; x<=1.2; x+=V) { 
	      if ( ( ( (x*x + y*y - 1)*(x*x + y*y - 1)*(x*x + y*y - 1) - x*x*y*y*y ) <= 0 ) ) 
	      printf("*"); else printf(" "); 
		  } 
	   printf("\n"); 
	} 
	getchar();
	system("pause"); 
	return 0; 
}

