#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    deque<char> dq;
    bool flag=true;
    rep(i,(int)s.size()) {
        if(s[i]=='R') {
            flag=!flag;
        } else {
            if(flag) {
                if(!dq.empty()&&dq.back()==s[i]) {
                    dq.pop_back();
                } else {
                    dq.push_back(s[i]);
                }
            } else {
                if(!dq.empty()&&dq.front()==s[i]) {
                    dq.pop_front();
                } else {
                    dq.push_front(s[i]);
                }
            }
        }
    }
    while(!dq.empty()) {
        if(flag) {
            cout << dq.front();
            dq.pop_front();
        } else {
            cout << dq.back();
            dq.pop_back();
        }
    }
    cout << endl;
    return 0;
}