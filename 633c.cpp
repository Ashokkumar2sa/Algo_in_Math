#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

#define ll long long int
#define vll vector<ll>
int p = 97; int m = 1e9;

int hash_cal(string s){
   int c = 0;
   
    for(int i=0;i<s.length();i++){
        if(s[i]>=65 && s[i]<=90 ) s[i] = s[i]-64;
        else if(s[i]>=97 && s[i]<=122) s[i] = s[i]-96+26;
        
        int x = (int)pow(p,i);
       // cout << x << " ";
        x =  x*s[i];
        x = x%m;
        c+=x;
    }
    return c;
}

int main(){
   ll n ;
   cin >> n;
   string s;
   cin >> s;
   
   string A;
   for(int i = n-1;i>=0;i--) A.push_back(s[i]);
   
  // cout << s << " " << A << " ";
 
 /*  vector<int> val(n);
   val = string_hash(A);
   for(int i=0;i<n;i++) cout << val[i] << " ";*/
   
   // cout<< endl;
    
   int m;
   cin >> m;
   vector<string> B(m);
   for(int i=0;i<m;i++) cin >> B[i];
   
  // for(int i=0;i<m;i++) cout << B[i] << " ";
   
   map<string, int> match;
   for(int i=0;i<m;i++){
       int x = hash_cal(B[i]);
       match[B[i]] = x;
       //cout << match[B[i]] << " " ;
   }
   //cout << endl;
   vector<string> final;
   
   string temp;
   for(int i=0;i<n;i++){
       temp+=A[i];
       for(int j =0;j<m;j++){
           if(match[B[j]] == hash_cal(temp) ){
               final.push_back(B[j]);
              // cout << B[j] << " ";
               temp = "";
               break;
           }
       }
   }
  // cout << final[0] <<  " " ;
   for(int i=0;i<final.size();i++) cout << final[final.size()-1-i] << " " ;
 
    return 0;
}










