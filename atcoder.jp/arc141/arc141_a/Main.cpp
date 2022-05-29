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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ma=9;
        string s=to_string(n);
        int x=s.size();
        const auto &res=enum_div(x);
        rep(i,x-2) ma=10*ma+9;
        for(auto u:res) {
            if(u==x) continue;
            string t,r;
            rep(i,u) t+=s[i];
            r=to_string(stoll(t)-1);
            string str1,str2;
            rep(i,x/u) {
                str1+=t;
                str2+=r;
            }
            if(n>=stoll(str1)) ma=max(ma,stoll(str1)); 
            if(n>=stoll(str2)) ma=max(ma,stoll(str2)); 
        }
        cout << ma << endl;
    } 
    return 0;
}