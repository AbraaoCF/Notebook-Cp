//Catapult the ball spoj sparse table
#include <bits/stdc++.h>
#include <math.h> 
#define maxx 1000100
using namespace std;

long long n,q,st[20][maxx], arr[maxx];
long long x,y;
int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++){ cin >> arr[i]; st[0][i] = arr[i]; }
	for(int j = 1; j <= log2(n); j++){
		for(int i = 1; i <= n; i++){
			st[j][i] = max(st[j-1][i],st[j-1][i+(int)pow(2,j-1)]);
		}
	}
	long long cnt  = 0;
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
	
		if(x>y)swap(x,y);
		if(y-x == 1) {cnt++;continue;}
		x++;y--;
		long long loga = (int)log2(y-x+1);
		long long k = pow(2,loga);
		if(max(st[loga][x],st[loga][y+1-k]) <= arr[x-1]) cnt++;
	}  
	cout << cnt << endl;
	return 0;
}
