
#include <bits/stdc++.h>
using namespace std;

//calculate gcd  using ax + by = gcd(a,b)
//naive method
/*

int inverse(int i, int prime){
     int x;
    
     for(int x=1;x<prime ;x++){
         if((i*x)%prime == 1) return x;
     }
     return -1;
}

*/

int gcdExtended(int a, int b, int *x, int *y)
{
	// Base Case
	if (a == 1)
	{
		*x = 1;
		*y = 0;
		return b;
	}

	int x1, y1; 
	int gcd = gcdExtended(b%a, a, &x1, &y1);
    cout << gcd<< endl;
    cout << x1 << " " << y1 << endl;
	
	*x = y1 - (b/a) * x1;
	*y = x1;
  cout << *x << " " << *y << endl;
  
  cout << endl;
	return gcd;
}


int main()
{
	int x, y, a = 37, b = 73;
	int g = gcdExtended(a, b, &x, &y);
	cout << "GCD(" << a << ", " << b << ") = " << g << endl;
	return 0;
}


