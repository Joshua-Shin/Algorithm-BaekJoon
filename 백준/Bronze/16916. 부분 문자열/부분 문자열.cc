#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    char str[1000001], str2[1000001];
    cin >> str >> str2;
    char * ptr = strstr(str, str2);
    if(ptr==NULL) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}