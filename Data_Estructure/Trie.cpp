// [SPOJ-ADAINDEX] 
#include<bits/stdc++.h>
using namespace std;
int trie[8600000][26], cnt[8600000][26];
int nxt = 1;

void add (string s){
    int node = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        if(trie[node][s[i] - 'a'] == 0) {
            cnt[node][s[i] - 'a']++;
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        }
        else {
            cnt[node][s[i] - 'a']++;
            node = trie[node][s[i] - 'a'];
        }
    }
}
 
int find (string s) {
    int idx = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++){
        if (trie[idx][s[i] - 'a'] == 0)
            return 0;
        else
        	res = cnt[idx][s[s.size()-1] - 'a'];
            idx = trie[idx][s[i] - 'a'];
	}
    return res;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    
    while(n--){
        string s; cin >> s;
        add(s);
    }
    while(m--){
    	string s; cin >> s;
    	int ans = find(s);
	cout << ans << "\n";
    }

    return 0;  
}
