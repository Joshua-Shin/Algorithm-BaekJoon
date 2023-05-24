#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int sum[26][200001]; // sum[x][y] = 문자열 s의 0부터 y까지의 범위에서 문자 x의 개수.
int c2i(char ch) {
    return ch - 'a';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> n;

    sum[c2i(s[0])][0] = 1;

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j < s.size(); j++) {
            if(c2i(s[j]) == i)
                sum[i][j] += (sum[i][j-1] + 1);
            else
                sum[i][j] += sum[i][j-1];
        }
    }
    while(n--) {
        char ch; int st, en;
        cin >> ch >> st >> en;
        if(st == 0)
            cout << sum[c2i(ch)][en] << '\n';
        else     
            cout << sum[c2i(ch)][en] - sum[c2i(ch)][st-1] << '\n';
    }    
}