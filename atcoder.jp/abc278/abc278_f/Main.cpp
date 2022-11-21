#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n;
vector<string> s;
vector<vector<bool>> mem,val;

bool rec(int bit,int p) {
    if(mem[bit][p]) return val[bit][p];
    bool res=false;
    rep(i,n) {
        if(bit>>i&1) continue;
        if(s[p].back()!=s[i][0]) continue;
        res|=!rec(bit|1<<i,i); 
    }
    mem[bit][p]=true;
    val[bit][p]=res;
    return res;
}

int main() {
    cin >> n;
    s.resize(n);
    rep(i,n) cin >>s[i];
    mem.resize(1<<n,vector<bool> (n));
    val.resize(1<<n,vector<bool> (n));
    rep(i,n) if(!rec(1<<i,i)) {
        cout << "First" << endl;
        return 0;
    } 
    cout << "Second" << endl;
    return 0;
}