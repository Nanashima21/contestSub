#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

bool is_pd(string s) {
    string rs=s;
    reverse(all(rs));
    return (s==rs);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n,k;
        string s;
        cin >> n >> k >> s;
        k%=2*n;
        if(k==0) k=2*n;
        string ns(k,'0');
        rep(i,n) {
            if(i<k) ns[i]=s[n-i-1];
            if(k-i-1>=0) ns[k-i-1]=s[i];
        }   
        cout << ((is_pd(s+ns)&&is_pd(ns+s)) ? "Yes" : "No") << '\n';
    }
    return 0;
}