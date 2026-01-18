#include<iostream>
using namespace std;
void Race(int a,int x,int y)
{
   /* if(a<x&&a<y)
    {
        if(x>y)
        {
            if(((x-y)<<(x-a))&&((x-y)<<(y-a)))
                cout<<"yes"<<endl;
            else
                cout<<"NO"<<endl;
        }
         if(x<y)
        {
            if(((y-x)<(x-a))&&((y-x)<(y-a)))
                cout<<"yes"<<endl;
            else
                cout<<"NO"<<endl;
        }
         if(x==y)
        {
            if(((x-y)<(x-a))&&((x-y)<(y-a)))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }*/
  if(a>>x&&a<<y)
    cout<<"NO"<<endl;
}
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
    Race(a,b,c);
}
