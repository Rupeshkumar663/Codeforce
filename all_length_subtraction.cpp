#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t))
        return 0;
    while(t--){
        int n;
        cin>>n;
        vector<int>p(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
         vector<int>b(n+1);
        for(int i=0;i<n;i++){
           b[p[i]]=i;
        }
        int m=n+1;
        int maxi=0;
        int count=0;
        bool result=true;
        for(int i=n;i>=1;i--){
            m=min(m,b[i]);
            maxi=max(maxi,b[i]);
            count++;
            if(maxi-m+1!=count)
            {
                result=false;
                break;
            }
        }
        cout<<(result?"YES\n":"NO\n");
    }
    return 0;
}

