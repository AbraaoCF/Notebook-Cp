// [Gym-101845A]
#include <bits/stdc++.h>
using namespace std;
#define maxx 100100
#define mp make_pair
#define sec second
typedef pair<int,int> ii;
typedef long long ll;
const int MOD = 1e9 + 7;

struct Matrix{
    vector< vector<long long> > mat; // the contents of matrix as a 2D-vector
    int n_rows, n_cols; // number of rows and columns

    Matrix(vector< vector<long long> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<long long> > result(n_rows, vector<long long>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % MOD;
                }
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }
};

Matrix fast_exponentiation(Matrix m, long long power){

    Matrix result({{0,0},{0,0}});
	if(power  == 1) return m;
	if(!(power & 1)){
		result = fast_exponentiation(m,power/2);
		return result * result;
	}
	else{
		result = fast_exponentiation(m,power-1);
		return result * m;
	}
    
}
Matrix m({{16,9,4,1,0},
          {1 ,0,0,0,0},
          {0 ,1,0,0,0},
          {0 ,0,1,0,0},
          {0 ,0,0,1,0}});

Matrix o({{1},
          {0},
          {0},
          {0},
          {0}});
int main(){
    long long n; cin >> n;
    Matrix ans = o;
    if(n/10 >= 1) ans =fast_exponentiation(m, max(1ll,n/10)) * o;
    if(n >= 45) {
        if(n%10 >= 5)  cout << (ans.mat[0][0] + ans.mat[1][0] + ans.mat[2][0] + ans.mat[3][0] )%MOD << endl;
        else  cout << (ans.mat[0][0] + ans.mat[1][0] + ans.mat[2][0] + ans.mat[3][0] + ans.mat[4][0])%MOD << endl;
    }
    else  cout << (ans.mat[0][0] + ans.mat[1][0] + ans.mat[2][0] + ans.mat[3][0] + ans.mat[4][0])%MOD << endl;

  return 0;
} 
