#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    map<string, int> strMap;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strMap[s]++;
    }
    int answer = 0;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(strMap.find(s) != strMap.end()) answer++;
    }
    cout << answer;
    
}