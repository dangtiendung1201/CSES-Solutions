#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e18 + 100;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 2e6 + 10;


void Zfunction(int z[], string s) {
    int n = (int)s.size();
    for (int i = 1; i <= n; i++) z[i] = 0;
    int L = 1, R = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= R) z[i] = min(z[i - L + 1], R - i + 1);
        while (i + z[i] <= n && s[z[i]] == s[i + z[i] - 1]) z[i]++;
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
}

int z[maxN];
int dp[1005][105];
int cost[105][26];
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = (int)s.size();
    string t;
    for (int i = 0; i < m; i++) {
        for (int c = 0; c < 26; c++) {
            string nxt = t + char(c + 'A');
            ///find longest suffix in nxt = prefix in s
            string p = s + "*" + nxt;
            Zfunction(z, p);
            int res = 0;
            for (int i = m + 2; i <= m + (int)nxt.size() + 1; i++) {
                if (i + z[i] == m + (int)nxt.size() + 2) {
                    res = z[i];
                    break;
                }
            }
            cost[i][c] = res;
        }
        t += s[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j]) {
                for (int c = 0; c < 26; c++) {
                    int next_j = cost[j][c];
                    dp[i + 1][next_j] = (dp[i + 1][next_j] + dp[i][j]) % MOD;
                }
            }
        }
        int cost_dp = 1LL * dp[i][m] * 26 % MOD;
        dp[i + 1][m] = (dp[i + 1][m] + cost_dp) % MOD;
    }
    cout << dp[n][m];
}
void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
