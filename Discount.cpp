#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t))
        return 0;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         vector<long long>b(k);
        for(int i=0;i<k;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end(),greater<long long>());
        sort(b.begin(),b.end());
        long long result=0;
        for(int i=0;i<n;i++){
            result+=a[i];
        }
        int index=0;
        for(int i=0;i<k;i++){
            int x=b[i];
            if(index+x-1>=n){
                break;
             }
            index+=x-1;
            result-=a[index];
            index++;
        }
        cout<<result<<endl;
    }
    return 0;
}
