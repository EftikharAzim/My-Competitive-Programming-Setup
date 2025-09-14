#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// ======================== FAST I/O & BASIC SETUP ========================
#define FASTIO                                                                                                         \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr)
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// ======================== TYPE ALIASES ========================
using ll = long long;
using ull = unsigned long long;
using u64 = uint64_t;
using u128 = __uint128_t;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

// Policy-based data structures
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ======================== CONSTANTS ========================
const int LOG = 20;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// Direction arrays
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {1, 0, -1, 1, -1, 1, 0, -1};
const int knight_x[8] = {2, 1, -1, -2, -2, -1, 2, 1};
const int knight_y[8] = {1, 2, 2, 1, -1, -2, -1, -2};

// ======================== ADVANCED DEBUG SYSTEM ========================
#ifndef ONLINE_JUDGE
namespace DEBUG {
template <typename T>
concept is_iterable = requires(T&& x) { begin(x); } && !is_same_v<remove_cvref_t<T>, string>;

void print(const char* x) {
    cerr << x;
}
void print(char x) {
    cerr << "\'" << x << "\'";
}
void print(bool x) {
    cerr << (x ? "T" : "F");
}
void print(string x) {
    cerr << "\"" << x << "\"";
}

template <typename T> void print(T&& x) {
    if constexpr (is_iterable<T>) {
        if (size(x) && is_iterable<decltype(*(begin(x)))>) {
            // 2D containers
            int f = 0;
            cerr << "\n~~~~~\n";
            for (auto&& i : x) {
                cerr << setw(2) << left << f++;
                print(i);
                cerr << "\n";
            }
            cerr << "~~~~~\n";
        } else {
            // 1D containers
            int f = 0;
            cerr << "{";
            for (auto&& i : x) {
                if (f++) cerr << ", ";
                print(i);
            }
            cerr << "}";
        }
    } else if constexpr (requires {
                             x.first;
                             x.second;
                         }) {
        // Pairs
        cerr << '(';
        print(x.first);
        cerr << ", ";
        print(x.second);
        cerr << ')';
    } else {
        cerr << x;
    }
}

template <typename T, typename... V> void printer(const char* names, T&& head, V&&... tail) {
    int bracket = 0, i = 0;
    for (; names[i] != '\0' && (names[i] != ',' || bracket != 0); i++) {
        if (names[i] == '(' || names[i] == '<' || names[i] == '{')
            bracket++;
        else if (names[i] == ')' || names[i] == '>' || names[i] == '}')
            bracket--;
    }
    cerr.write(names, i) << " = ";
    print(head);
    if constexpr (sizeof...(tail)) {
        cerr << " | ";
        printer(names + i + 1, tail...);
    } else {
        cerr << "]\n";
    }
}
} // namespace DEBUG
#define debug(...) cerr << "[Line " << __LINE__ << "] [", DEBUG::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbg(x) debug(x)
#else
#define debug(...)
#define dbg(x)
#endif

// ======================== UTILITY FUNCTIONS ========================
// Random number generation
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
ll randll(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

// Bit manipulation
int popcount(ll x) {
    return __builtin_popcountll(x);
}
int clz(ll x) {
    return __builtin_clzll(x);
} // count leading zeros
int ctz(ll x) {
    return __builtin_ctzll(x);
} // count trailing zeros
bool has_bit(ll mask, int i) {
    return (mask >> i) & 1;
}
ll set_bit(ll mask, int i) {
    return mask | (1LL << i);
}
ll clear_bit(ll mask, int i) {
    return mask & ~(1LL << i);
}
ll flip_bit(ll mask, int i) {
    return mask ^ (1LL << i);
}

// ======================== MODULAR ARITHMETIC ========================
inline void norm(ll& a) {
    a %= MOD;
    if (a < 0) a += MOD;
}
inline ll mod_add(ll a, ll b) {
    a %= MOD;
    b %= MOD;
    norm(a);
    norm(b);
    return (a + b) % MOD;
}
inline ll mod_sub(ll a, ll b) {
    a %= MOD;
    b %= MOD;
    norm(a);
    norm(b);
    return (a - b + MOD) % MOD;
}
inline ll mod_mul(ll a, ll b) {
    a %= MOD;
    b %= MOD;
    norm(a);
    norm(b);
    return (a * b) % MOD;
}

inline ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

inline ll mod_inv(ll a) {
    return mod_pow(a, MOD - 2);
}
inline ll mod_div(ll a, ll b) {
    return mod_mul(a, mod_inv(b));
}

// ======================== FLOATING POINT UTILITIES ========================
bool eq(double a, double b) {
    return abs(a - b) <= EPS;
}
bool lt(double a, double b) {
    return a + EPS < b;
}
bool le(double a, double b) {
    return a < b + EPS;
}
bool gt(double a, double b) {
    return a > b + EPS;
}
bool ge(double a, double b) {
    return a + EPS > b;
}

// ======================== CUSTOM HASH (for unordered containers) ========================
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// ======================== ADDITIONAL UTILITIES ========================
template <typename T> T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

template <typename T> T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template <typename T> T ceil_div(T a, T b) {
    return (a + b - 1) / b;
}

// Binary search templates
template <typename T, typename F> T binary_search_first_true(T lo, T hi, F&& pred) {
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        if (pred(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

template <typename T, typename F> T binary_search_last_true(T lo, T hi, F&& pred) {
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (pred(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

// ======================== MAIN TEMPLATE ========================
void solve() {}

int main() {
    FASTIO;

    int tc = 1;
    // cin >> tc; // Remove this line for single test case problems

    while (tc--) {
        solve();
    }

    return 0;
}