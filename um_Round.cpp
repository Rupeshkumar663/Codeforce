#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>result;
        int power=1;
        while(n>0){
            if(n%10>0)
            result.push_back((n%10)*power);
            n/=10;
            power*=10;
        }
      cout<<result.size()<<endl;
      for(auto x:result)
        cout<<x<<" ";
      cout<<endl;
    }
    return 0;
}