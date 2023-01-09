#include <iostream>
using namespace std;
int a[1001];
int d[1001];
int d2[1001];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n; // 1<= <=1000
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = 1;
        d2[i] = 1;
    }

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (a[i]>a[j]&&d[i]<d[j]+1)
                d[i] = d[j]+1;

    for (int i = n-1; i >= 1; i--)
        for (int j = n; j >= i; j--)
            if (a[i]>a[j]&&d2[i]<d2[j]+1)
                d2[i] = d2[j]+1;

    for(int i =1; i<=n; i++)
        ans = max(ans, d[i]+d2[i]-1);

    cout << ans << '\n';

    return 0;
}