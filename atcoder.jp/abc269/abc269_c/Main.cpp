#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    int cnt=0;
    vector<ll> v;
    while(n>0) {
        cnt++;
        if(n%2==1) v.push_back(cnt);
        n/=2;
    }
    for(int bit=0;bit<(1<<(int)v.size());bit++) {
        ll sum=0;
        rep(i,(int)v.size()) if(1<<i&bit) sum+=1LL<<(v[i]-1);
        cout << sum << endl;
    }
    return 0;
}