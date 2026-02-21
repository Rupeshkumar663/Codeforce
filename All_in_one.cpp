#include<bits/stdc++.h>
using namespace std;
long long solve(vector<long long>a,long long n,long long h,long long k){
    long long s=0;
    for(long long x:a) 
        s+=x;
    long long f=(h-1)/s;
    long long time=f*(n+k);
    long long rem=h-f*s;
    long long p=0;
    for(long long i=0;i<n;i++){
        p+=a[i];
        if(p>=rem){
            time+=i+1;
            break;
        }
    }
    return time;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,h,k;
        cin>>n>>h>>k;
        vector<long long>a(n);
        for(long long i=0;i<n;i++)
            cin>>a[i];
        long long result=solve(a,n,h,k);
        long long S=0;
        for(long long x:a) S+=x;
        long long f=(h-1)/S;
        long long rem=h-f*S;
        long long pref=0;
        long long pref_min=LLONG_MAX;
        vector<long long>suff_max(n);
        suff_max[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
            suff_max[i]=max(a[i],suff_max[i+1]);
        for(int i=0;i<n-1;i++){
            pref+=a[i];
            pref_min=min(pref_min,a[i]);
            if(pref>=rem){
                result=min(result,f*(n+k)+i+1);
                break;
            }
            long long improve=pref-pref_min+suff_max[i+1];
            if(improve>=rem){
                result=min(result,f*(n+k)+i+1);
            }
        }
        cout<<result<<"\n";
    }
}