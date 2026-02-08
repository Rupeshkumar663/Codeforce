#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<string>a(k);
        for(int i=0;i<k;i++) cin>>a[i];
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                nums.push_back(i);
                if(i*i!=n) nums.push_back(n/i);
            }
        }
        sort(nums.begin(),nums.end());
        string result;
        for(int d:nums){
            string cur(d,'?');
            bool check=true;
            for(int r=0;r<d;r++){
                bool count[26];
                for(int c=0;c<26;c++) count[c]=1;
                for(int pos=r;pos<n;pos+=d){
                    bool tmp[26]={0};
                    for(int i=0;i<k;i++)
                        tmp[a[i][pos]-'a']=1;
                    for(int c=0;c<26;c++)
                        count[c]&=tmp[c];
                }
                int p=-1;
                for(int c=0;c<26;c++)
                    if(count[c]){
                        p=c;
                        break;
                    }
                if(p==-1){
                    check=false;
                    break;
                }
                cur[r]=char('a'+p);
            }
            if(check){
                result.resize(n);
                for(int j=0;j<n;j++)
                    result[j]=cur[j%d];
                break;
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}
