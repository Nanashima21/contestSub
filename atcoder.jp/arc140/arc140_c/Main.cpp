#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x;
    cin >> n >> x;
    vector<int> v,p;
    if(n%2==0&&n/2+1==x) {
        for(int i=x,j=x-1;i<=n&&j>0;i++,j--) {
            p.push_back(i);
            p.push_back(j);
        }
    } else {
        p.push_back(x);
        rep(i,n) if(i+1!=x) v.push_back(i+1);
        int r=(n-1)/2,l=r-1;
        while(true) {
            if(r>=n-1) break;
            p.push_back(v[r++]);
            if(l<0) break;
            p.push_back(v[l--]);
        } 
    }
    rep(i,(int)p.size()) {
        if(i) cout << " ";
        cout << p[i];
    } cout << endl;

    /*
    vector<int> v(n);
    rep(i,n) v[i]=i+1;
    int ma=0;
    do {
        if(v[0]!=x) continue;
        vector<ll> p,b(n,INF);
        rep(i,n-1) p.push_back(abs(v[i]-v[i+1]));
        int pos=0;
        rep(i,n-1) {
            int it=lower_bound(all(b),p[i])-b.begin();
            b[it]=p[i];
            pos=max(pos,it+1);
        }
        rep(i,(int)v.size()) {
            if(i) cout << " ";
            cout << v[i];
        } cout << ": " << pos << endl;
        ma=max(ma,pos);
    } while(next_permutation(all(v)));
    cout << ma << endl;
    */
    return 0;
}