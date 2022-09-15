#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int l=0;
    ll ans=1;
    if(s[l]==t[l]) {
        ans*=3;
        l++;
    } else {
        ans*=6;
        l+=2;
    }
    for(;l<n;) {
        if(s[l]!=t[l]) {
            if(s[l-1]==t[l-1]) {
                ans*=2;
                ans%=mod;
            } else {
                ans*=3;
                ans%=mod;
            }
            l+=2;
        } else {
            if(s[l-1]==t[l-1]) {
                ans*=2;
                ans%=mod;
            }
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}