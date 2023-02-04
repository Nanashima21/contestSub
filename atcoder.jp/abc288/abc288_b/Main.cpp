#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k;
    cin >> n >> k;
    vector<string> s(k);
    rep(i,k) cin >> s[i];
    string str;
    rep(i,n-k) cin >> str;
    sort(all(s));
    rep(i,k) cout << s[i] << endl;
    return 0;
}