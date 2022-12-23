#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel; // 가격, 무게
    multiset<int> bag;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        jewel.push_back({b,a});
    }
    sort(jewel.begin(), jewel.end());
    reverse(jewel.begin(), jewel.end());

    for(int i = 0; i<k; i++) {
        int temp;
        cin >> temp;
        bag.insert(temp);
    }

    ll answer = 0;
    for(auto e: jewel) {
        int value = e.first;
        int weight = e.second;
        auto it = bag.lower_bound(weight);
        if(it!=bag.end()) {
            bag.erase(it);
            answer += value;
        } 
    }
    cout << answer << '\n';
    return 0;
}