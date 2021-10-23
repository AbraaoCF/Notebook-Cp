// [CodeForces-471D]
#include <bits/stdc++.h> 
using namespace std;
int lps[20000000];
vector<int>pat,txt;
int ans = 0;
void computeLPSArray(int M) { 
	int len = 0; 
	
	lps[0] = 0;
	
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else { 
			if (len != 0) len = lps[len - 1]; 
			else { 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 
void KMPSearch() {
	int M = pat.size(); 
	int N = txt.size(); 

	computeLPSArray(M); 

	int i = 0;
	int j = 0;
    while (i < N) { 
    	// cout << "q";
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 
		
		if (j == M) { 
			// cout << "j";
			ans++;
			j = lps[j - 1]; 
		} 
	
		else if (i < N && pat[j] != txt[i]) { 

			if (j != 0) j = lps[j - 1]; 
			else i = i + 1; 
		} 
	} 
}

int main(){
	int n,m; cin >> n >> m;
	int aux = 0;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		if(i)txt.push_back(a-aux);
		aux = a;
	}
	int aux2 = 0;
	for(int i = 0; i < m; i++){
		int a; cin >> a;
		if(i)pat.push_back(a-aux2);
		aux2 = a;
	}
	if(m==1){cout << n << "\n"; return 0;}
	if(n==1){cout << 0 << "\n"; return 0;}
	KMPSearch();

	cout << ans << "\n";
}
