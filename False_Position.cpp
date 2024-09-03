#include<bits/stdc++.h>
using namespace std;
double func(double k,double l, double m,double x)
{
    return k*x*x+l*x+m;
}
void false_position(double k,double l,
 double m,double a,double b)
{
    if(func(k,l,m,a)*func(k,l,m,b)>=0){
        cout<<" Wrong assumption of a & b\n";
        return;
    }
    double c0=a,c; double epsilon=.001; double e;
    int step=0;
    while(e>=epsilon)
    {
        c=(a*func(k,l,m,b)-b*func(k,l,m,a))/
        (func(k,l,m,b)-func(k,l,m,a));
        e=fabs(c-c0);
        if(func(k,l,m,c)==0.0) break;
        if(func(k,l,m,c)<0) a=c;
        else b=c;
        c0=c; step++;
    }
    cout<<"Root :"<<c<<"\n";
    cout<<"No of steps ="<<step<<"\n";

}
int main(){
    double k,l,m,a,b;
    cout<<"Enter the variables\n";
    cin>>k>>l>>m;
    cout<<"Enter value of initial assumptions(a&b)\n";
    cin>>a>>b;
    false_position(k,l,m,a,b);
    return 0;
}
