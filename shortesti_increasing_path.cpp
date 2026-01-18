/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(2*n,0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<2*n;j++){
                if(nums[j]==0 && nums[i+j]==0 && i+j<2*n){
                    nums[j]=nums[i+j]=i;
                    break;
                }
            }
        }
        for(int i=0;i<2*n;i++){
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
       if(y>x) cout<<"2"<<endl;
       else if(y>=2 &&x-y>=2)cout<<"3"<<endl;
       else cout<<"-1"<<endl;

        
    }
    return 0;
}