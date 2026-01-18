/*/*#include<bits/stdc++.h>
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
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(2*n+1,0);
        for(int i=n;i>=1;i--){
            for(int j=1;j<=2*n;j++){
                if(nums[j]==0 && nums[i+j]==0 && i+j<2*n){
                    nums[j]=nums[i+j]=i;
                    break;
                }
            }
        }
        for(int i=1;i<=2*n;i++){
            if(i>1)
            cout<<' ';
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int m=2*n;
        vector<int>a(m+1,0);
        for(int x=n;x>=1;--x){
            int i=0,j=0;
            for(int k=1;k<=m;k++){
                if (a[k]==0 &&i==0) {
                    i=k;
                    j=i+x;
                }
                if(i!=0&&j<=m&&a[j]==0){
                    break; 
                }
                if(i!=0)j+=x;  
            }
            a[i]=a[j]=x;
        }
        reverse(a.begin(),a.end());
        for(int i=1;i<=m;i++) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
