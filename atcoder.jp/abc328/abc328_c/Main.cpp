#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> cnt(n);
    rep(i,n-1) {
        cnt[i+1]+=cnt[i];
        if(s[i]==s[i+1]) cnt[i+1]++; 
    }
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << cnt[r]-cnt[l] << endl;
    }
    return 0;
}