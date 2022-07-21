#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

ll f(string s) {
    ll res=0;
    reverse(all(s));
    rep(i,(int)s.size()) res=res*10+(s[i]-'0');
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v,pow3(11);
    pow3[0]=1;
    for(int i=1;i<=10;i++) pow3[i]=3*pow3[i-1];
    set<string> se;
    for(int k=3;k<=10;k++) {
        for(int bit=0;bit<pow3[k];bit++) {
            string str;
            vector<bool> flag(3);
            rep(i,k) {
                int j=(bit/pow3[i])%3;
                if(j==0) str+='3';
                else if(j==1) str+='5';
                else str+='7';
                flag[j]=true;
            }
            if(flag[0]&&flag[1]&&flag[2]) se.insert(str);
        }
    }
    for(auto u:se) v.push_back(f(u));
    sort(all(v));
    cout << upper_bound(all(v),n)-v.begin() << endl; 
    return 0;
}