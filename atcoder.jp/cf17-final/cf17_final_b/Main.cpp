#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(3,0);
    for(auto u:s) cnt[u-'a']++;
    bool flag=true;
    rep(i,3) rep(j,3) if(abs(cnt[i]-cnt[j])>1) flag=false;
    cout << (flag ? "YES" : "NO") << endl; 
    return 0;
}