#include<iostream>
using namespace std;
int main()
{   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    int a,b,c;
cin>>a>>b>>c;
if(a+b>=c&&a+c>=b&&b+c>=a)
    cout<<"YES";
    else cout<<"NO";
    
//system("pause");
return 0;    
}  
