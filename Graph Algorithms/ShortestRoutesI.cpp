#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());


void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

string DIRECT = "URDL";
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxN = 3e5 + 100;
typedef pair<int, int> i2;
typedef pair<long long, int> i2LL;
int n, m;
vector<i2> adj[maxN];
long long dist[maxN];

void Dijkstra(int S, long long dist[maxN]) {
    priority_queue<i2LL, vector<i2LL>, greater<i2LL> > Q;
    for (int i = 1; i <= n; i++) dist[i] = INF_LL;
    dist[S] = 0;
    Q.push({0, S});
    while ((int)Q.size() != 0) {
        i2LL A = Q.top(); Q.pop();
        long long du = A.first;
        int u = A.second;
        if (du != dist[u]) continue;
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
}
void sol() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});
    }
    Dijkstra(1, dist);
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
}
void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        sol();
    }
}

int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
