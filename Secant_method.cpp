#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
double l,m,n;
double func(double x){
    return l*x*x+m*x+n;
}
double secant(double x1,double x2,double E){
    int step=0; double c,x0,xm;
    if(func(x2)*func(x1)<0){
        do{
            x0=(x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
            c= func(x1)*func(x2);
            x1=x2;x2=x0;
            step++;
            if(c==0.0) break;
            xm= (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
        }while(fabs(x0-xm)>E);
    }
    else{
        cout<<"Can't find root within this interval\n";
    }
    cout<<"Root: "<<x0<<"\n";
    cout<<"No of steps :"<<step<<"\n";
}
int main(){
    cout<<"Enter the variables for the polynomial equation\n";
    cin>>l>>m>>n;
    cout<<"Enter the initial values(x1,x2) and error\n";
    double x1,x2,e;
    cin>>x1>>x2>>e;
    secant(x1,x2,e);

    return 0;
}
