#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll LLINF = 1e18;

int Left[500000];
int Right[500000];
vector<pair<ll, ll>> v;

int findLeft(int here) {

    int &ret = Left[here];
    if (ret != -1) return ret;

    ll a = v[here].first;
    ll b = v[here].second;

    int t = lower_bound(v.begin(), v.end(), make_pair(a - b, -1ll)) - v.begin();

    ret = t;
    for (; t < here; t++)
        ret = min(ret, findLeft(t));
    return ret;
}

int findRight(int here) {

    int &ret = Right[here];
    if (ret != -1) return ret;

    ll a = v[here].first;
    ll b = v[here].second;

    int t = upper_bound(v.begin(), v.end(), make_pair(a + b, LLINF)) - v.begin();

    ret = t - 1;
    for (; here < t; here++)
        ret = max(ret, findRight(here));
    return ret;
}

int cache[301][301]; // 도미노 블록 개수가 지금 최대 300개라 이리 한듯
int func(int a, int b) {

    int &ret = cache[a][b];
    if (ret != -1) return ret;

    if (a > b) return ret = 0;
    if (Right[a] >= b || Left[b] <= a) return ret = 1;

    ret = 1e9;
    for (int i = a; i <= b; i++)
        ret = min(ret, func(a, Left[i] - 1) + func(Left[i], Right[i]) + func(Right[i] + 1, b));
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; // 도미노 개수
    cin >> n;
    v.resize(n);

    memset(cache, -1, sizeof(cache));

    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b; // x좌표, 막대 높이
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());

    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    for (int i = 0; i < n; i++) {
        findLeft(i);
        findRight(i);
    }

    // 모든 도미노를 넘어뜨리기 위해서 넘어뜨려야하는 최소 개수
    cout << func(0, n - 1) << '\n';

    return 0;
}