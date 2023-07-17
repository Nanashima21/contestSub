#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
  int n,t,m;
  cin >> n >> t >> m;
  vector<vector<bool>> flag(n,vector<bool>(n));
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    flag[a][b] = true;
    flag[b][a] = true;
  }

  int ans = 0;
  vector<vector<int>> team;
  auto f = [&](auto f, int i) -> void {
    if (i == n) {
      if (team.size() == t) ans++;
      return;
    }
    rep(j,team.size()) {
      bool ok = true;
      for (int p : team[j]) if (flag[i][p]) ok = false;
      if (!ok) continue;
      team[j].push_back(i);
      f(f,i+1);
      team[j].pop_back();
    }
    team.push_back(vector<int>(1,i));
    f(f,i+1);
    team.pop_back();
  };
  f(f,0);
  cout << ans << endl;
  return 0;
}