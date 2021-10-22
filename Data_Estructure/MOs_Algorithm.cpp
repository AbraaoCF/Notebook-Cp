// MO's Algorithm for Holes Codeforces
#include <bits/stdc++.h>
using namespace std;
#define maxx 200010
struct hole{
	int power, qtd, ultimo, nxt;
}; hole arr[maxx];

int n, t, block;

void update(int x){
	for(int i = x; i >= (x/block)*block; i--){
		if (i + arr[i].power >= n){ 
			arr[i].qtd = 1;
			arr[i].nxt = n;
			arr[i].ultimo = i;
		}
		else if (i/block != (arr[i].power+i)/block){ 
			arr[i].nxt = i + arr[i].power;
			arr[i].qtd = 1;
			arr[i].ultimo = i;
		}
		else{ 
			arr[i].qtd = arr[arr[i].power+i].qtd + 1; 
			arr[i].ultimo = arr[arr[i].power+i].ultimo;
			arr[i].nxt = arr[arr[i].power+i].nxt;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> arr[i].power;

	block = sqrt(n);
	for(int i = n-1; i >= 0; i--){
		if (i + arr[i].power >= n){
			arr[i].qtd = 1;
			arr[i].nxt = n;
			arr[i].ultimo = i;
		}
		else if (i/block != (arr[i].power+i)/block){
			arr[i].nxt = arr[i].power+i;
			arr[i].qtd = 1;
			arr[i].ultimo = i;
		}
		else{
			arr[i].qtd = arr[arr[i].power+i].qtd + 1;
			arr[i].ultimo = arr[arr[i].power+i].ultimo;
			arr[i].nxt = arr[arr[i].power+i].nxt;
		}
	}

	while(t--){
		int k, a, b; cin >> k >> a; a--;
		if (k == 0){
			cin >> b; arr[a].power = b; update(a);
		}
		else{
			int last, ans = 0;
			for (int i = a; i < n; i = arr[i].nxt){
				last = arr[i].ultimo;
				ans += arr[i].qtd;
			}
			cout << last + 1 << " " << ans << "\n";
		}
	}
	return 0;
}
