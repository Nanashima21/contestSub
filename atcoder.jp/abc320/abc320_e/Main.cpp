#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,pl>> v1;
    vector<pl> v2;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    rep(i,m) {
        ll t,w,s;
        cin >> t >> w >> s;
        v1.push_back({t,{w,s}});
        pq.push(make_pair(t,2));
        v2.push_back(make_pair(t+s,i));
        pq.push(make_pair(t+s,1));
    }
    int idx=0,idx2=0;
    sort(all(v2));
    vector<ll> tot(2*n),erased(m,-1);
    set<int> se;
    rep(i,2*n) se.insert(i);
    while(!pq.empty()) {
        int t=pq.top().second;
        pq.pop();
        if(t==2) {
            int it=*se.begin();
            tot[it]+=v1[idx].second.first;
            erased[idx]=it;
            if(it<n) se.erase(it);
            idx++;
        } else {
            se.insert(erased[v2[idx2].second]);
            idx2++;
        }
    }
    rep(i,n) cout << tot[i] << endl;
    return 0;
}