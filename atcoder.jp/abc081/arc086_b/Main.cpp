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
    vector<ll> a(n);
    ll ma=0,idx=0;
    bool pos=true;
    rep(i,n) {
        cin >> a[i];
        if(abs(a[i])>ma) {
            ma=abs(a[i]);
            idx=i;
            if(a[i]<0) pos=false;
            else pos=true;
        }
    }
    vector<pair<int,int>> ans;
    rep(i,n) {
        if(pos&&a[i]<0) {
            a[i]+=ma;
            ans.push_back({idx+1,i+1});
        }
        if(!pos&&a[i]>0) {
            a[i]-=ma;
            ans.push_back({idx+1,i+1});
        }
    }
    if(!pos) ma*=-1;
    rep(i,n) {
        if(pos) {
            a[i]+=ma;
            ans.push_back({idx+1,i+1});
            if(a[i]>ma) {
                ma=a[i];
                idx=i;
            }
        } else {
            a[n-i-1]+=ma;
            ans.push_back({idx+1,n-i});
            if(a[n-i-1]<ma) {
                ma=a[n-i-1];
                idx=n-i-1;
            }
        }
    }
    cout << (int)ans.size() << endl;
    for(auto u:ans) cout << u.first << " " << u.second << endl;
    return 0;
}