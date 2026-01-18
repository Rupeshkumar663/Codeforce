#include <bits/stdc++.h>
using namespace std;

long long minTurns(long long h,long long d){
    long long x=0,y=0,health=h,z=0;
    while(y<d){
        if(health>z){
            z++;
            health-=z;
            y++;
        }else{
            health++;
            z=0;
        }
        x++;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        long long h,d; cin>>h>>d;
        cout<<minTurns(h,d)<<"\n";
    }
}
