/*#include<bits/stdc++.h>
using namespace std;
class solution
{
public:
    int digit()
   {
    int x;
    cin>>x;
    vector<int>arr;
    while(x>0)
    {
        int y=x%10;
        x=x/10;
        arr.push_back(y);
    }
    sort(arr.begin(),arr.end());
    return arr.front();
   }
};
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y;
    cin>>t;
    for(;t--;)
    {
        y=10;
        cin>>x;
        while(x>0)
        {
            y=min(y,x%10);
            x=x/10;
        }
        cout<<y<<"\n";
    }
}
