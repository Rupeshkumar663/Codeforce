#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       long long a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<"\n";
            continue;
        }
        long long f=a^b;
        if(f%2){
            cout<<-1<<"\n";
            continue;
        }
       long long m1=f/2;
       long long m2=a^m1;
        if(m1>a || m2>a)
         cout<<-1<<"\n";
        else 
        cout<<2<<"\n"<<m1<<" "<<m2<<"\n";
    }
    return 0;
}
