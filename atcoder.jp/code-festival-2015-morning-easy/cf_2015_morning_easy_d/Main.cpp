#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n;

int solve(string s,string t) {
	int x=(int)s.size();
	int y=(int)t.size();
	vector<vector<bool>> flag(y,vector<bool> (x,false));
	rep(i,x) rep(j,y) if(s[i]==t[j]) flag[j][i]=true;
    vector<vector<int>> dp(y+1,vector<int> (x,0));
    for(int i=1;i<=y;i++) {
        int ma=0;
        rep(j,x) {
            dp[i][j]=dp[i-1][j];
            if(flag[i-1][j]) dp[i][j]=max(dp[i][j],ma+1);
            ma=max(ma,dp[i-1][j]);
        }
    }
	int ma=0;
    rep(i,x) ma=max(ma,dp[y][i]);
	return n-ma*2;
}

int main() {
    string s;
	cin >> n >> s;
	int ans=n;
	for(int i=1;i<n;i++) {
		string sf=s.substr(0,i),sb=s.substr(i,n-i);
		ans=min(ans,solve(sf,sb));
		ans=min(ans,solve(sb,sf));
	}
	cout << ans << endl;
    return 0;
}