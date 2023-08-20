#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<pl> p;

long double dis(int i, int j) {
    long double sum=0.0;
    sum+=(p[i].first-p[j].first)*(p[i].first-p[j].first);
    sum+=(p[i].second-p[j].second)*(p[i].second-p[j].second);
    return sqrt(sum);
}

int main() {
    ll n;
    cin >> n;
    rep(i,n) {
        ll x,y;
        cin >> x >> y;
        p.push_back({x,y});
    }

    vector<vector<long double>> dist(n,vector<long double> (100,INF));
    dist[0][0]=0;
    
    rep(i,n) {
        rep(j,30) {
            if(dist[i][j]==INF) continue;
            for(int k=1;k<30;k++) {
                if(i+k>=n) break;
                dist[i+k][j+k-1]=min(dist[i+k][j+k-1],dist[i][j]+dis(i,i+k));
            }
        }
    }
    long double ma=dist[n-1][0];
    for(int i=1;i<=30;i++) ma=min(ma,dist[n-1][i]+pow(2,i-1));
    printf("%.10Lf\n",ma);
    return 0;
}