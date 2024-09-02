#include<bits/stdc++.h>
using namespace std;

double func(double k,double l,double m,
double x)
{
   return k*x*x+l*x+m;
}
void bisection(double k,double l,double m,
double a,double b){
    if(func(k,l,m,a)*func(k,l,m,b)>=0){
        cout<<"You haven't assumed "<<
        "the initial values correctly\n";
        return;
    }
    double c;
    while((b-a)>=.001){
        c=(a+b)/2;
        if(func(k,l,m,c)==0) break;
        if(func(k,l,m,c)<0) a=c;
        else b=c;
    }
    cout<<"root: "<<c;

}
int main()
{
    double a,b;
    double k,l,m;
    cout<<"Enter the variables\n";
    cin>>k>>l>>m;
    cout<<"Enter initial assumptions\n";
    cin>>a>>b;
    bisection(k,l,m,a,b);

    return 0;
}
