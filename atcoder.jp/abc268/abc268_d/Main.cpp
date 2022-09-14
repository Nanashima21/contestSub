#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n,m;
set<string> se;
vector<string> s;
string ans="-1";

void dfs(int cnt,vector<int> &v,string str) {
    int sz=(int)str.size();
    if(sz>16) return;
    if(cnt==n) {
        if(3<=sz&&se.find(str)==se.end()) ans=str;
        return;
    } 
    string l="_";
    for(int i=0;i<=16-(sz+1+(int)s[v[cnt]].size());i++) {
        dfs(cnt+1,v,str+l+s[v[cnt]]);
        l+="_";
    }
}

int main() {
    cin >> n >> m;
    s.resize(n);
    rep(i,n) cin >> s[i];
    set<string> ng;
    rep(i,m) {
        string t;
        cin >> t;
        se.insert(t);
        string ngs;
        for(auto u:t) {
            ngs+=u;
            if(u=='_') break;
        }
        ng.insert(ngs);
    }
    vector<int> v(n);
    rep(i,n) v[i]=i;
    do {
        if(ng.find(s[v[0]])!=ng.end()) continue;
        string str=s[v[0]];
        dfs(1,v,str);
        if(ans!="-1") {
            cout << ans << endl;
            return 0;
        }
    } while(next_permutation(all(v)));
    cout << ans << endl;
    return 0;
}