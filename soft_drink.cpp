#include<bits/stdc++.h>
using namespace std;
int main(){
    
    
        int n,k,l,c,d,p,nl,np;
        cin>>n>>k>>l>>c>>d>>p>>nl>>np;
        int m=k*l;
        int t1=m/nl;
        int t2=c*d;
        int t3=p/np;
      int result=min({t1,t2,t3});
      cout<<result/n<<endl;
    
return 0;
}
