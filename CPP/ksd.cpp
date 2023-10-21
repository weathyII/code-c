#include<iostream>
using namespace std;
int main()
{
    double n,m,a=0,b=7,t;
    cin>>n>>m;
    while(a<=n-m)
    {
        a+=b;;
        b*=0.98;
    }
    if(a+b*.98>m+n)
    {
        cout<<"n"<<endl;
    }
    else
    {
        cout<<"y"<<endl;
    }
}