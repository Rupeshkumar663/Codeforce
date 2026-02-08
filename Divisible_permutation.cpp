#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>p(n+1);
        vector<bool>used(n+1,false);
        p[n]=1;
        used[1]=true;
        for(int i=n-1;i>=1;i--){
            for(int x=1;x<=n;x++){
                if(!used[x] && abs(x-p[i+1])%i==0){
                    p[i]=x;
                    used[x]=true;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<p[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
