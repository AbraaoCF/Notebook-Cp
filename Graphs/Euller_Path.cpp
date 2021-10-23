// 508D - EullerPath example
#include <bits/stdc++.h>
using namespace std;
#define maxx 100010

vector <int> ladj[maxx];
int in[maxx];
int out[maxx];
vector <int> path;

void dfs(int node) {
	while(out[node] > 0) {
		int next = ladj[node][out[node]-1];
		out[node]--;
		dfs(next);
	}
	path.push_back(node);
}

int main() {
	int n; cin >> n;
	int startNode;
	for(int i = 0; i < n; i++) {
			string substr; cin >> substr;

			ladj[substr[0]*256 + substr[1]].push_back(substr[1]*256 + substr[2]);
			
			startNode = substr[0]*256 + substr[1];
			
			in[substr[1]*256 + substr[2]]++;
			out[substr[0]*256 + substr[1]]++;
	}

	int qStartNodes = 0, qEndNodes = 0, qInvalid = 0;
    
	for(int i = 0; i < maxx; i++) {
		if(in[i] == out[i]) continue;
		if(in[i]+1 == out[i]) {
			startNode = i;
			qStartNodes++;
			continue;
		}
		if(in[i] == out[i]+1) {
			qEndNodes++;
			continue;
		}
		qInvalid++;
	}

	if(qInvalid > 0 || qStartNodes > 1 || qEndNodes > 1 || qStartNodes != qEndNodes) {
		cout << "NO\n";
		return 0;
	}
	
	dfs(startNode);
	if(path.size() != n+1) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	reverse(path.begin(), path.end());

	string s = "";
	for(int i = 0; i < path.size(); i++) {		
		if(i==0) s += path[i]/256;
		s += path[i]%256;
	}
	cout << s << "\n";

	return 0;
}
