#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int time = a * 60 + b + c;
    int hh = time / 60;
    time %= 60;
    hh %= 24;
    cout << hh << ' ' << time;
}