#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<ll> x,y;

bool f(int i,int j,int k) {
    ll z=abs((x[i]-x[k])*(y[j]-y[k])-(x[j]-x[k])*(y[i]-y[k]));
    if(z%2==0&&z>0) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    x.resize(n);
    y.resize(n);
    rep(i,n) cin >> x[i] >> y[i];
    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) {
                if(f(i,j,k)) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}