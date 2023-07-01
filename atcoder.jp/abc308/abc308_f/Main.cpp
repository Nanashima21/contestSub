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
	vector<ll> p(n),l(m),d(m);
	multiset<ll> ms1,ms2;
	rep(i,n) {
		cin >> p[i];
		ms1.insert(p[i]);
	}
	rep(i,m) cin >> l[i];
	rep(i,m) cin >> d[i];
	vector<pl> v;
	{
		rep(i,m) v.push_back({d[i],l[i]});
		sort(rall(v));
		rep(i,m) {
			auto it=ms1.lower_bound(v[i].second);
			if(it==ms1.end()) continue;
			//cout << *it << " " << v[i].first << " " << v[i].second << endl;;
			ms2.insert(*it-v[i].first);
			ms1.erase(ms1.find(*it));
		}
	}
	ll ans=0;
	for(auto u:ms1) ans+=u;
	for(auto u:ms2) ans+=u;
	cout << ans << endl;
	return 0;
}