#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,a,b;
        cin>>l>>a>>b;
        int maxi=0;
        int i=0;
        while(i<=l){
            int temp=(a+(i*b))%l;
           maxi=max(maxi,temp);
            i++;
        }
        cout<<maxi<<"\n";
    }
    return 0;
}