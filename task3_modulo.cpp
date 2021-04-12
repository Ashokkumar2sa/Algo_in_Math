#include <bits/stdc++.h>
using namespace std;
const int N=100000;
const int mod=19;
#define ll long long int
ll fact[N];
ll invfact[N];
ll inv[N];
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
void factorialsComputation()
{
    fact[0]=fact[1]=1;
    invfact[0]=invfact[1]=1;
    for(int i=2;i<N;i++)
    {
        ll temp=i;//divide the number by mod to make it free od mod so that the remaining number leaves remainder other than 0
        while(temp%mod==0)
            temp/=mod;
        fact[i]=(fact[i-1]*temp)%mod;
        invfact[i]=(invfact[i-1]*modInverse(temp))%mod;
    }
}
ll ncr(ll n,ll r)
{
    //if the numerator is have  more number of mod than denominator then it would have 0 as remainder when we do nodulo p
    ll upper=0;
    ll temp=n;
    while(temp!=0)
    {
        temp/=mod;
        upper+=temp;
    }
    ll down=0;
    temp=r;
    while(temp!=0)
    {
        temp/=mod;
        down+=temp;
    }
    temp=n-r;
    while(temp!=0)
    {
        temp/=mod;
        down+=temp;
    }
    if(upper>down)
        return 0;
  //else we calculate normal modulo
    ll ans=fact[n]*invfact[r];
    ans%=mod;
    ans*=invfact[n-r];
    ans%=mod;
    return ans;
}
int main()
{
    factorialsComputation();
    cout<<ncr(20,2);
}