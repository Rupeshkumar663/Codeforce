/*#include<bits/stdc++.h>
using namespace std;
int recycling(vector<long long>&arr,long &c)
{
    int n=arr.size();
    int N=0;
    for(int i=0;i<n;i++)
    {
          if(arr[i]>c)
            N++;
        for(int j=n-1;j>=i+1;j--)
         arr[j]=2*arr[j];
    }
    return N;
}
int main()
{
   vector<long long>arr={29,25,2,12,15,42,14,6,16,9};
   //vector<int>arr={10,4,15,1,8};
    long x=30;
    int result=recycling(arr,x);
    cout<<result;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1;
    int x;
    cin>>x;
    while(t<=x){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i%2==1){
              cout<<"x"<<" ";
            }
            if(i%2==0){
             cout<<"-x"<<" ";
            }
        }
        if(n%2==0){
            cout<<0<<endl;
        }
       if(n%2==1)
          cout<<t<<endl;
     t++;
    }
}
    */
#include<bits/stdc++.h>
using namespace std;
int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int x;
 cin>>x;
 while(x>0){
    int y,n;
    cin>>y;
    cin>>n;
    if(n%2==0)
      cout<<0<<endl;
    else
    cout<<y<<endl;
    x--;
  }  
 return 0;
}