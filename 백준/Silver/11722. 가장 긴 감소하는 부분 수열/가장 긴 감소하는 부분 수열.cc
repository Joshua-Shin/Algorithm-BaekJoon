#include <iostream>
using namespace std;
int n, a[1000], d[1000], ans;
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        d[i] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] > a[i] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
    for (int i = 0; i < n; i++)
        ans = max(ans,d[i]);
    cout << ans;
    return 0;
}