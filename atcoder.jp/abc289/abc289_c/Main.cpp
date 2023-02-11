#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(m,vector<int> ());
    rep(i,m) {
        int c;
        cin >> c;
        rep(j,c) {
            int a;
            cin >> a;
            a--;
            v[i].push_back(a);
        }
    }
    int cnt=0;
    for(int i=0;i<1<<m;i++) {
        vector<bool> flag(n,false);
        rep(j,m) if(i>>j&1) {
            rep(k,v[j].size()) flag[v[j][k]]=true;
        }
        bool check=true;
        rep(j,n) if(!flag[j]) check=false;
        if(check) cnt++;
    }
    cout << cnt << endl;
    return 0;
}