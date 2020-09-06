#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxP = 1e4 + 10;
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

int power(int a, int n) {
    int res = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) res = 1LL * a * a % MOD;
    }
    return res;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

void Minimize(int &a, int b) {
    a = min(a, b);
}

void Maximize(int &a, int b) {
    a = max(a, b);
}

void mul(int &a, int b) {
    a = 1LL * a * b % MOD;
}

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

const int maxN = 5e3 + 10;
const int maxM = 110;
long long dp[maxN][maxN];
int x[maxN];
void sol() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        dp[i][i] = x[i];
        sum += x[i];
    }
    ///dp[i][j] = score1 - score2
    ///player1: max dp[i][j]
    ///player2: min dp[i][j]
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if ((j - i + 1) & 1) {
                ///dp[i][j] = score1 - score2
                ///-(dp[i + 1][j], dp[i][j - 1]) is score1 - score2
                dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
            }
            else {
                ///dp[i][j] = score2 - score1
                ///-(dp[i + 1][j], dp[i][j - 1]) is score2 - score1
                dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
            }
        }
    }
    cout << (sum + dp[1][n]) / 2;
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
