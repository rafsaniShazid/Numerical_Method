// This code solves any 2nd degree polynomial equation
// whose derivative won't be zero 
#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
double l,m,n;
#define epsilon .001
double func(double x){
   return l*x*x+m*x+n;
}
double deriv(double x){
    return 2*l*x+ m;
}
double newton_raphson(double x){
    double h = func(x)/deriv(x);
    while(fabs(h)>epsilon)
    {   
        double d= deriv(x);
        if(fabs(d)<.00001){
            cout<<"Root can't be determined for this equation"<<
            "with newton_raphson method\n"; return 0.0;
        }
        h= func(x)/d;
        x=x-h;
    }
    cout<<"Root: "<<x<<"\n";
}
int main()
{
    cout<<"Enter the a,b & c for the 2nd"<< 
    " degree polynomial equation\n";
    cin>>l>>m>>n;
    double x0;
    cout<<"Say your initial guess\n";
    cin>>x0;
    newton_raphson(x0);
    return 0;
}
