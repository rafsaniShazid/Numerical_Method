#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;

void printMatrix(vector<vector<double>>& mat){
    int n= mat.size();
    forr(i,0,n){
        forr(j,0,n+1){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void gauss_eli(vector<vector<double>>& mat)
{
    int n= mat.size();
    forr(i,0,n){
        double max_element= abs(mat[i][i]);
        int maxRow= i;
        // loop to find the max element of a column
        forr(k,i+1,n)
        {
            if(abs(mat[k][i])>max_element){
                max_element=abs(mat[k][i]);
                maxRow=k;
            }
        }
        // swapping the first row with the with the row
        // that contains the highest element
        swap(mat[maxRow],mat[i]);
        forr(k,i+1,n){
            double factor= mat[k][i]/mat[i][i];
            forr(j,i,n+1){
            mat[k][j]-=factor*(mat[i][j]);
            }
        }
    }
}
void row_echelon(vector<vector<double>> &mat)
{
    int n= mat.size();
    forr(i,0,n)
    {
        double pivot= mat[i][i];
        forr(j,i,n+1){
            mat[i][j]/=pivot;
        }
    }
}
void jordan_eli(vector<vector<double>>& mat){
    int n= mat.size();
    for(int i=n-1;i>=0;i--){
        double pivot= mat[i][i];
        forr(j,i,n+1){
            mat[i][j]/=pivot;
        }

        forr(k,0,i){
        double factor= mat[k][i]/mat[i][i];
            forr(j,0,n+1){
                mat[k][j]-=factor*mat[i][j];
            }
        }
    }


}

int main(){
    int n; cin>>n;
    vector<vector<double>> mat(n,vector<double>(n+1));
    forr(i,0,n){
        forr(j,0,n+1){
            cin>>mat[i][j];
        }
    }
    gauss_eli(mat);
    jordan_eli(mat);
    row_echelon(mat);
    printMatrix(mat);
    return 0;
}
