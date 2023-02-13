#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=(1LL<<61)-1;
vector<vector<ll>> h;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    h.resize(n,vector<ll> ());
    map<ll,set<char>> mp; 
    rep(i,n) {
        cin >> s[i];
        reverse(all(s[i]));
        
        //mp[s[i].substr(0,(int)s[i].size()-1)].insert(s[i].back());
        h[i].push_back(0);
        
        for(int j=1;j<(int)s[i].size();j++) {
            h[i].push_back(((100LL*h[i][j-1])%mod+(s[i][j-1]-'a'+1))%mod);
            //cout << h[i][j] << " " << s[i].substr(0,j) << endl;;
        }
        mp[h[i][(int)s[i].size()-1]].insert(s[i].back());
    }
    int ans=0;
    rep(i,n) {
        set<char> suf;
        for(int j=(int)s[i].size()-1;j>=0;j--) {
            suf.insert(s[i][j]);
            for(char c:mp[h[i][j]]) {
                if(suf.find(c)!=suf.end()) ans++;
            }
        }
    }
    cout << ans-n << endl;
    return 0;
}