// (i) check the matrix is diagonal or not
// (ii) implement gauss- siedel with mean value error
#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
#define f1(x,y,z) (14-2*y-z)/4
#define f2(x,y,z) (10-x+z)/5
#define f3(x,y,z) (20-x-y)/8
void check_diagonal_dominant(
    double a1,double b1,double c1,double r1,
    double a2,double b2,double c2,double r2,
    double a3,double b3,double c3,double r3)
{
    if ((abs(a1)>= abs(b1)+abs(c1)) &&
    (abs(b2)>= abs(c2)+abs(a2)) &&
    (abs(c3)>= abs(b3)+abs(a3))
    ) {
        cout<<"Diagonally Dominant \n";

    }
    else{
        cout<<"The matrix is not diagonally dominant\n";
    }
}

int main(){
    double a1,b1,c1,r1;
    double a2,b2,c2,r2;
    double a3,b3,c3,r3;
    cin>>a1>>b1>>c1>>r1;
    cin>>a2>>b2>>c2>>r2;
    cin>>a3>>b3>>c3>>r3;
    // After rerranging
    check_diagonal_dominant( a1,b1,c1,r1,
    a2,b2,c2,r2,a3,b3,c3,r3);
    double e1,e2,e3,x0=0,y0=0,z0=0,x1,y1,z1;
    cout<<setprecision(6)<<fixed; int iter=1;
    double e;
    do{
        x1= f1(x0,y0,z0);
        y1= f1(x1,y0,z0);
        z1= f1(x1,y1,z0);
        e1= fabs(x0-x1);
        e2= fabs(y0-y1);
        e3= fabs(z0-z1);
        x0=x1;y0=y1;z0=z1;
        e=(e1+e2+e3)/3;
    cout<<"iter: "<<iter<<" x1="<<x1<<" y1="<<y1<<" z1="<<z1<<" e="<<e<<"\n";
        iter++;

    }while((e1+e2+e1)/3>=.0001);
    return 0;
}
