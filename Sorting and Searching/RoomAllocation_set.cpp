#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxN = 3e5 + 10;
const int maxM = 20;
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

struct customer {
    int id, a, b;
    customer(){};
    customer(int _id, int _a, int _b) {
        id = _id;
        a = _a;
        b = _b;
    }
    bool operator < (const customer &A) {
        if (b != A.b) return b < A.b;
        return a < A.a;
    }
};
customer arr_customer[maxN];
typedef pair<int, int> i2;
int res[maxN];
void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr_customer[i].a >> arr_customer[i].b;
        arr_customer[i].id = i;
    }
    sort(arr_customer + 1, arr_customer + 1 + n);
    set<i2> rooms;
    {
        rooms.insert({arr_customer[1].b, 1});
        res[arr_customer[1].id] = 1;
    }
    int k = 1;
    for (int i = 2; i <= n; i++) {
        auto it = rooms.lower_bound({arr_customer[i].a, -1});
        if (it == rooms.begin()) {
            k++;
            rooms.insert({arr_customer[i].b, k});
            res[arr_customer[i].id] = k;
        }
        else {
            it--;
            int old_k = it->second;
            rooms.erase(it);
            rooms.insert({arr_customer[i].b, old_k});
            res[arr_customer[i].id] = old_k;
        }
    }
    cout << k << '\n';
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
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
