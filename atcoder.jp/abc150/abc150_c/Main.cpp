#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) c[i]=i+1;
    int num1=0,num2=0,cnt=0;
    do {
        if(a==c) num1=cnt;
        if(b==c) num2=cnt;
        cnt++;
    } while(next_permutation(all(c)));
    cout << abs(num1-num2) << endl;
    return 0;
}