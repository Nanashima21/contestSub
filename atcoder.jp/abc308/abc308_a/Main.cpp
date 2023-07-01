#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
	vector<int> s(8);
	bool flag=true;
	rep(i,8) {
		cin >> s[i];
		if(100>s[i]) flag=false;
		if(s[i]>675) flag=false;
		if(s[i]%25!=0) flag=false;
	}
	vector<int> ss=s;
	sort(all(ss));
	if(ss!=s) flag=false;
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}