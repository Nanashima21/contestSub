#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<int> v(3);
    rep(i,3) cin >> v[i];
    sort(rall(v));
    vector<vector<vector<double>>> dp(101,vector<vector<double>> (101,vector<double> (101,0.0)));
    for(int i=99;i>=1;i--) {
        for(int j=99;j>=0;j--) {
            for(int k=99;k>=0;k--) {
                dp[i][j][k]+=(i*1.0)/(i+j+k)*(dp[i+1][j][k]+1.0);
                dp[i][j][k]+=(j*1.0)/(i+j+k)*(dp[i][j+1][k]+1.0);
                dp[i][j][k]+=(k*1.0)/(i+j+k)*(dp[i][j][k+1]+1.0);
            }
        }
    }
    printf("%.10f\n",dp[v[0]][v[1]][v[2]]);
    return 0;
}