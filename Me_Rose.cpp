#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        vector<int>arr(n+2,0);
        for(int i=0;i<n;i++)arr[nums[i]]++;

        if(k==0){
            cout<<arr[0]<<"\n";
            continue;
        }

        bool missing=false;
        for(int i=0;i<k;i++){
            if(arr[i]==0){
                missing=true;
                break;
            }
        }

        int ans=arr[k];
        if(missing)ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
