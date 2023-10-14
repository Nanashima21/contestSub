#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> p2,p3;
    p2.push_back(1);
    p3.push_back(1);
    while(p2.back()*2<=1e18) {
        p2.push_back(p2.back()*2);
    }
    while(p3.back()*3<=1e18) {
        p3.push_back(p3.back()*3);
    }
    vector<ll> v;
    for(auto x:p2) for(auto y:p3) {
        if(x<=1e18/y) v.push_back(x*y);
    } 
    sort(all(v));
    cout << (binary_search(all(v),n) ? "Yes" : "No") << endl;
    return 0;
}