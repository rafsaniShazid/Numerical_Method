// solution of linear equation by gauss sidel
#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
/*
Main equations:

27x-6y-z=85.....(1)
6x+15+2z=72.....(2)
x+y+54z=110.....(3)

*/
// defining the equations here
#define f1(y,z) (6*y+z+85)/27 //x
#define f2(x,z) (-6*x-2*z+72)/15 //y
#define f3(x,y) (-x-y+110)/54 //z

int main(){
    float x0=0,y0=0,z0=0,x1,y1,z1,e1,e2,e3,e;
    // setting up precision after the decimal point    
    cout<<setprecision(5)<<fixed;
    int step=1;
    cout<<"Enter precision \n"; cin>>e;
    do{
        x1=f1(y0,z0);
        y1=f2(x1,z0);
        z1=f3(x0,y1);
        // checking the errors
        cout<<step<<"\tx= "<<x1<<", y= "<<y1<<
        ", z= "<<z1<<"\n";
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
