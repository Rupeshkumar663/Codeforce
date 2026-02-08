#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>p(n);
        for(int i=0;i<n;i++) 
        cin>>p[i];

        int l=-1;
        for(int i=0;i<n;i++){
            if(p[i]!=n-i){
                l=i;
                break;
            }
        }

        if(l==-1){
            for(int i=0;i<n;i++) 
            cout<<p[i]<<" ";
            cout<<"\n";
            continue;
        }

        int target=n-l;
        int r=l;
        for(int i=l;i<n;i++){
            if(p[i]==target){
                r=i;
                break;
            }
        }
        reverse(p.begin()+l,p.begin()+r+1);
        for(int i=0;i<n;i++) 
        cout<<p[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
