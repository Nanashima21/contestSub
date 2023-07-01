#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int main() {
	ll h,w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s[i];
	vector<vector<vector<bool>>> dp(h,vector<vector<bool>> (w,vector<bool> (5,false)));
	if(s[0][0]=='s') dp[0][0][0]=true;
	string snu="snuke";
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()) {
		int cx=q.front().second;
		int cy=q.front().first;
		char c=s[cy][cx];
		int idx=0;
		rep(i,5) if(c==snu[i]) idx=i;
		q.pop();
		rep(l,4) {
			int nx=cx+dx[l],ny=cy+dy[l];
			if(ny<0||ny>=h||nx<0||nx>=w) continue;
			if(s[ny][nx]==snu[(idx+1)%5]) {
				if(dp[ny][nx][(idx+1)%5]) continue;
				dp[ny][nx][(idx+1)%5]=true;
				q.push({ny,nx});
			}
		}
	}
	rep(i,h) rep(j,w) {
		rep(k,5) {
			if(dp[i][j][k]) {
				rep(l,4) {
					int nx=j+dx[l],ny=i+dy[l];
					if(ny<0||ny>=h||nx<0||nx>=w) continue;
					if(s[ny][nx]==snu[(k+1)%5]) dp[ny][nx][(k+1)%5]=true;
				}
			}
		}
	}
	bool flag=false;
	rep(i,5) if(dp[h-1][w-1][i]) flag=true;
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}