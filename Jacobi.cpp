#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
/*
a1x+b1y+c1z=r1
a2x+b2y+c2z=r2
a3x+b3y+c3z=r3
*/
int main(){
    cout<<"Enter the variables \n";
    float a1,b1,c1,a2,b2,c2,a3,b3,c3,r1,r2,r3;
    float e1,e2,e3,e,x0=0,y0=0,z0=0,x1,y1,z1;
    cin>>a1>>b1>>c1>>r1;
    cin>>a2>>b2>>c2>>r2;
    cin>>a3>>b3>>c3>>r3;
    cout<<setprecision(6)<<fixed;
    cout<<"Enter precision\n"; cin>>e;
    int step=1;
    do{
        x1= (-b1*y0-c1*z0+r1)/a1;
        y1=(-a2*x0-c2*z0+r2)/b2;
        z1= (-a3*x0-b3*y0+r3)/c3;
        cout<<step<<"\t"<<"x= "<<x1<<", y= "<<y1<<", z= "<<z1<<"\n";
        e1= fabs(x0-x1);
        e2= fabs(y0-y1);
        e3= fabs(z0-z1);
        x0=x1;
        y0=y1;
        z0=z1;
    step++;
    }while(e1>e && e2>e && e3>e);
    return 0;
}
