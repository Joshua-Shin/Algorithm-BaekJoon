#include <bits/stdc++.h>
using namespace std;
int ans[26];
int main()
{
    string str;
    cin >> str;
    for(auto x : str)
    {
        ans[x-'a']++;
    }
    for(int i =0; i<26; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}