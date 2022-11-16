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
    int n;
    cin >> n;
    vector<ll> v;
    ll i=2;
    while((int)v.size()<n&&i<=55555) {
        if(isprime(i)&&i%5==1) v.push_back(i); 
        i++;
    }
    rep(i,(int)v.size()) {
        if(i) cout << " ";
        cout << v[i];
    } cout << endl;
    return 0;
}