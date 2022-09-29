#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<ll> enum_div(ll n) {
    vector<ll> ret;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            ret.push_back(i);
            if(n/i!=i) ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
    //const auto &res=enum_div(n);
}

int main() {
    ll n;
    cin >> n;
    n*=2;
    const auto &res=enum_div(n);
    int cnt=0;
    for(auto u:res) if(u%2==0&&(n/u)%2==1) cnt++;
    cout << cnt*2 << endl;
    return 0;
}