#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	string s;
	cin >> s;
	vector<vector<ll>> ml(n,vector<ll> (3,0));
	vector<vector<ll>> xr(n,vector<ll> (3,0));
	if(s[0]=='M') ml[0][a[0]]++;
	for(int i=1;i<n;i++) {
		rep(j,3) ml[i][j]=ml[i-1][j];
		if(s[i]=='M') ml[i][a[i]]++;
	}
	if(s.back()=='X') xr[n-1][a.back()]++;
	for(int i=n-2;i>=0;i--) {
		rep(j,3) xr[i][j]=xr[i+1][j];
		if(s[i]=='X') xr[i][a[i]]++;
	}
	ll tot=0;
	for(int i=1;i<n-1;i++) {
		if(s[i]=='E') {
			rep(j,3) rep(k,3) {
				set<ll> se;
				rep(l,4) se.insert(l);
				se.erase(a[i]);
				if(ml[i][j]!=0) se.erase(j);
				if(xr[i][k]!=0) se.erase(k);
				tot+=*se.begin()*ml[i][j]*xr[i][k];
			}
		}
	}
	cout << tot << endl;
	return 0;
}