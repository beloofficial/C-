#include<iostream>
#include<string>
using namespace std;
int main()
{int i;
string s,q;
cin>>s>>q;

cout<<s.erase(3,2)<<" ";//������
cout<<q.substr(2,3);//��������
cout<<s.compare(q)<<" ";//����������
return 0;
}
