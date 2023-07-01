#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll gcd(ll x,ll y){
    if (y==0) return x;
    else return gcd(y,x%y);
}

struct frac{
    ll a,b;
    frac(ll _a=0,ll _b=1):a(_a),b(_b) {
        if(b==0) { a=1; return; }
        if(b<0) a=-a,b=-b;
        ll g=gcd(a,b);
        a/=g; b/=g;
    }
    bool operator<(const frac& x) const {
        return a*x.b < x.a*b;
    }
    bool operator==(const frac& x) const {
        return a==x.a && b==x.b;
    }
};

int main() {
	ll n;
	cin >> n;
	vector<pair<frac,int>> v; 
	rep(i,n) {
		ll a,b;
		cin >> a >> b;
		v.push_back({frac(a,a+b),-i});
	}
	sort(rall(v));
	rep(i,(int)v.size()) {
		if(i) cout << " ";
		cout << -v[i].second+1;
	} cout << endl;

	return 0;
}