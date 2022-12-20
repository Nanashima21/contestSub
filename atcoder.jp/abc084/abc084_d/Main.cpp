#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

bool isprime(ll x) {
    if(x<2) return 0;
    else if(x==2) return 1;
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}

int main() {
    int q;
    cin >> q;
    vector<ll> cnt(100100,0);
    vector<bool> flag(100100,false);
    for(int i=2;i<100100;i++) {
        cnt[i]+=cnt[i-1];
        if(isprime(i)) flag[i]=true;
        if(flag[i]&&flag[(i+1)/2]) cnt[i]++;
    }
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << cnt[r]-cnt[l-1] <<'\n';
    }
    return 0;
}