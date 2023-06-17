#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k,q;
    cin >> n >> k >> q;
    vector<ll> x(q),y(q);
    rep(i,q) {
        cin >> x[i] >> y[i];
        x[i]--;
    }
    
    set<pl> se1,se2;
    vector<ll> v(n,0);
    vector<bool> flag(n);
    if(n==k) {
        ll ans=0;
        rep(i,q) {
            ans-=v[x[i]];
            v[x[i]]=y[i];
            ans+=y[i];
            cout << ans << '\n';
        }
        return 0;
    }
    rep(i,k) {
        se1.insert({0,i});
        flag[i]=true;
    }
    for(int i=k;i<n;i++) {
        se2.insert({0,i});
        flag[i]=false;
    }
    ll tot=0;
    rep(i,q) {
        if(flag[x[i]]) {
            tot-=v[x[i]];
            auto it=se1.find({v[x[i]],x[i]});
            se1.erase(it);
            auto it2=se2.end();
            it2--;
            if(it2->first>=y[i]) {
                se1.insert({it2->first,it2->second});
                tot+=it2->first;
                flag[it2->second]=true;
                se2.erase(it2);
                se2.insert({y[i],x[i]});
                flag[x[i]]=false;
            } else {
                se1.insert({y[i],x[i]});
                flag[x[i]]=true;
                tot+=y[i];
            }
        } else {
            auto it=se2.find({v[x[i]],x[i]});
            se2.erase(it);
            auto it1=se1.begin();
            if(it1->first>=y[i]) {
                se2.insert({y[i],x[i]});
                flag[x[i]]=false;
            } else {
                se2.insert({it1->first,it1->second});
                tot-=it1->first;
                flag[it1->second]=false;
                se1.erase(it1);
                se1.insert({y[i],x[i]});
                flag[x[i]]=true;
                tot+=y[i];
            }
        }
        v[x[i]]=y[i];
        cout << tot << '\n';
    }
    return 0;
}