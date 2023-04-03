#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

void comb2(vector<vector<ll>> &v){
    for(int i=0;i<v.size();i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int k=1;k<v.size();k++){
        for(int j=1;j<k;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]);
        }
    }
}

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(rall(v));
    vector<vector<ll>> c(n+1,vector<ll>(n+1,0));
    comb2(c);
    double ma=0.0;
    rep(i,a) ma+=v[i];
    ma/=a;
    ll num=0,pos=0;
    rep(i,n) if(v[i]==v[a-1]) {
        num++;
        if(i<a) pos++;
    }
    ll cnt=0;
    if(pos==a) {
        for(pos=a;pos<=b;pos++) cnt+=c[num][pos];
    } else cnt+=c[num][pos];
    printf("%.10f\n",ma);
    cout << cnt << endl;
    return 0; 
}