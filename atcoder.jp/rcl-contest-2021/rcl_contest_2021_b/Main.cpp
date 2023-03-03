#include <bits/stdc++.h>
using namespace std;
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;
typedef pair<ll,ll> pl;

int N;
vector<vector<int>> in(40, vector<int> (40));
vector<vector<int>> out(40, vector<int> (40,0));
vector<vector<bool>> is_use(40, vector<bool> (40,false));
vector<vector<bool>> flag(40, vector<bool> (40,true));

const double Limit_time=1.85*CLOCKS_PER_SEC;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int Randint(int a, int b) {
    return a + rand() % (b-a+1);
}

double Randdouble() {
    return 1.0 * rand() / RAND_MAX;
}

int calc_dist_m(int x,int y,int nx,int ny) {
    return abs(nx-x) + abs(ny-y);
}

ll GetScore(vector<vector<int>>& v) {
    ll score = 0;
    bool is_valid = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!is_use[i][j]) continue;
            int delta = v[i][j];
            for (int y = max(0, i-delta); y <= min(N-1, i+delta); y++) {
                for (int x = max(0, j-delta); x <= min(N-1, j+delta); x++) {
                    if (i == y && j == x) continue;
                    if (calc_dist_m(i, j, y, x) > delta) continue;
                    if (is_use[y][x]) {
                        is_valid = false;
                        break;
                    }
                }
                if(!is_valid) break;
            }
            if(!is_valid) break;
            else score += v[i][j] * in[i][j];
        }
        if(!is_valid) break;
    }
    if(!is_valid) score = -1;
    return score;
}

void scatter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!is_use[i][j]) continue;
            int limit = N*N;
            queue<pair<int, int>> q;
            vector<vector<int>> dist(N, vector<int> (N, N*N)); 
            q.push({i, j});
            dist[i][j] = 0;
            while(!q.empty()) {
                int cy = q.front().first;
                int cx = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int ny = cy + dy[k];
                    int nx = cx + dx[k];
                    if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                    if (dist[ny][nx] != N*N) continue;
                    if (is_use[ny][nx]) {
                        limit = dist[cy][cx];
                        break;
                    }
                    dist[ny][nx] = dist[cy][cx] + 1;
                    q.push({ny, nx});
                }
                if (limit != N*N) break;
            }
            out[i][j] = limit;
            for (int y = 0; y < N; y++) 
                for (int x = 0; x < N ; x++)
                    if (dist[y][x] <= limit) flag[y][x] = false;
        }
    }
}

int main(int argc, char* argv[]) {
    int power_init = 15, power_sub = 2;
    if (argc == 3) {
        power_init = atoi(argv[1]);
        power_sub = atoi(argv[2]);
    }

    cin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> in[i][j];
    

    int threshold = power_init;

    while (threshold >= 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bool neighbor = false;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                    if (is_use[ny][nx]) neighbor = true;
                }
                if (!neighbor && flag[i][j] && in[i][j] >= threshold) is_use[i][j] = true;
            }
        }

        scatter();
        if (threshold == 0) break;
        threshold -= power_sub;
        if (threshold < 0) threshold = 0; 
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << " ";
            cout << out[i][j];
        }
        cout << endl;
    }
    return 0;
}