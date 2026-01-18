#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
      if((a+b+c)%3==0)
      {
        int x=(a+b+c)/3;
        if(x>=a&&b<=x)
       {
        cout<<"yes"<<endl;
       }
       else
       {
        cout<<"No"<<endl;
       }
      }
      else
      {
        cout<<"No"<<endl;
      }

   return 0;
}
