#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    int cnt1=0;
    vector<int> v;
    rep(i,10) if(s[i]=='o') v.push_back(i);
    int cnt=0;
    for(int i=0;i<10000;i++) {
        int a=i%10;
        int b=i/10%10;
        int c=i/100%10;
        int d=i/1000%10;
        set<int> se;
        if(s[a]=='o') se.insert(a);
        else if(s[a]=='x') continue;
        if(s[b]=='o') se.insert(b);
        else if(s[b]=='x') continue;
        if(s[c]=='o') se.insert(c);
        else if(s[c]=='x') continue;
        if(s[d]=='o') se.insert(d);
        else if(s[d]=='x') continue;
        vector<int> vec;
        for(auto u:se) vec.push_back(u);
        if(v==vec) cnt++;
    }
    cout << cnt << endl;
    return 0;
}