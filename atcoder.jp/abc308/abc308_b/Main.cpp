#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
	int n,m;
	cin >> n >> m;
	vector<string> s(n),d(m);
	vector<int> p(m+1);
	rep(i,n) cin >> s[i];
	rep(i,m) cin >> d[i];
	rep(i,m+1) cin >> p[i];
	map<string,int> mp;
	rep(i,m) mp[d[i]]=p[i+1];
	ll tot=0;
	rep(i,n) {
		if(mp.find(s[i])==mp.end()) tot+=p[0];
		else tot+=mp[s[i]];
	}
	cout << tot << endl;
	return 0;
}