#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(string s) {
    ll sum=0;
    bool flag=true;
    for(char c:s) {
        if('A'<=c&&c<='Z') flag=false;
        sum*=10;
        sum+=c-'0';
    }
    if(!flag) return -1;
    else return sum;
}

int main() {
    string s;
    cin >> s;
    bool flag=true;
    if(!('A'<=s[0]&&s[0]<='Z')) flag=false;
    if(!('A'<=s.back()&&s.back()<='Z')) flag=false;
    string str=s.substr(1,(int)s.size()-2);
    if((int)str.size()!=6) flag=false;
    if(!(100000<=f(str)&&f(str)<=999999)) flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}