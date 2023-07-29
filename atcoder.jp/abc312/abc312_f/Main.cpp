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
    vector<pl> p;
    vector<ll> c,nc,op;
    rep(i,n) {
        ll t,x;
        cin >> t >> x;
        p.push_back({t,x});
        if(t==0) c.push_back(x);
        if(t==1) nc.push_back(x);
        if(t==2) op.push_back(x);
    } 
    if((int)c.size()==0&&nc.size()==0) {
        cout << 0 << endl;
        return 0;
    }
    sort(rall(c));
    sort(rall(nc));
    sort(rall(op));
    int x=(int)op.size();
    rep(i,x-1) op[i+1]+=op[i];
    op.push_back(0);
    sort(all(op));
    x++;
    vector<ll> ma(x,0);
    int cidx=0,ncidx=0;
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    while(cidx<(int)c.size()&&(int)pq.size()<m) {
        ma[0]+=c[cidx];
        pq.push({c[cidx],0});
        cidx++;
    }
    for(int i=1;i<x;i++) {
        if(m==i) break;
        ma[i]=ma[i-1];
        //cout << m-i << " " << (int)pq.size() << " " << ma[i] << endl;
        while(!pq.empty()&&(int)pq.size()>m-i) {
            ma[i]-=pq.top().first;
            pq.pop();
        } 
        while((int)pq.size()<m-i&&ncidx<op[i]&&ncidx<(int)nc.size()) {
            ma[i]+=nc[ncidx];
            pq.push({nc[ncidx],1});
            ncidx++;
        } 
        while(!pq.empty()&&ncidx<op[i]&&ncidx<(int)nc.size()&&nc[ncidx]>pq.top().first) {
            ma[i]-=pq.top().first;
            pq.pop();
            ma[i]+=nc[ncidx];
            pq.push({nc[ncidx],1});
            ncidx++;
        }
    }
    cout << *max_element(all(ma)) << endl;
    return 0;
}