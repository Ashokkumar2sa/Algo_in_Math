#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

int hash_cal(string s){
    //cout << s << " ";
    long long int c = 0;
    int p = 97; int m = 1e9;
    for(int i=0;i<s.length();i++){
        
        if(s[i]>=65 && s[i]<=90 ) s[i] = s[i]-64;
        else if(s[i]>=97 && s[i]<=122) s[i] = s[i]-96+26;
        
        long long int x = (int)pow(p,i);
       // cout << x << " ";
        x =  x*s[i];
        x = x%m;
        c+=x;
    }
    return c;
}

int main(){
    string s = "Ashok";
    string s1 = "ashok";
   long long  int val = hash_cal(s);
   ll b =  hash_cal(s1);
   cout << val << " " << b << " " ;
    return 0;
}










