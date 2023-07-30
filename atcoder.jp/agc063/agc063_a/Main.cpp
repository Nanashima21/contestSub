#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n+1);
    int cnta=1,cntb=0;
    rep(i,n+1) {
        if(s[i]=='A') {
            a[i]=cnta;
            cnta+=2;
        } else {
            a[i]=cntb;
            cntb+=2;
        } 
    }
    vector<pl> p;
    rep(i,n+1) p.push_back({a[i],i});
    sort(all(p));
    set<int> se;
    rep(i,200200) se.insert(i);
    rep(i,n) {
        se.erase(p[i].second);
        if(s[*se.begin()]=='A') cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
    return 0;
}