#include <bits/stdc++.h>
#include<cmath>

//Task 2 - Print the factors of number from 1 to N in O(nlogn)
/*
 one way is :-
    void solve(int n){
        vector <int> factors[n];
        for(int i=1;i<=n ;i++){
            for(int j=i;j<=n;j+=i){
                factor[j].push_back(i);
            }
        }
    }
I did it in another way

*/
using namespace std;

const int N=100023;
int main()
{
    int primefactor[N]; 
    
    for(int i=1;i<N;i++)
    {
        primefactor[i]=i;
    }
    for(int i=N-1;i>1;i--)
    {
        if(primefactor[i]!=i)  // i.e. i is not prime
            continue;
        for(int j=i;j<N;j+=i)
            primefactor[j]=i;  // Since i is prime and divides j
    }
    int x;
    cin >> x;
    
    // Lets count no. of factors of x
    int factors=1;
    
    for(int i=1;i<x;i++){
        cout << i << " " << "1 " ; 
        int t = i;
      while(t!=1)
       {
          int p=primefactor[t];  // p is prime and divides x
          int cnt=0;   // It will store the maximum power of p dividing x
          while((t%p)==0)
          {   
              int w = pow(p, (cnt + 1)) ;
              cout << w << " " ; 
              t/=p;
              cnt++;
          }
      }
      
       cout << endl;
    }
   
   return 0;
}












