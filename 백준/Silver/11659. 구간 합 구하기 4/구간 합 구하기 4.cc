#include <iostream>
using namespace std;
int arr[100001];
int sum[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i =0; i<n; i++)
    {
        cin >> arr[i];
    }
    sum[0] = arr[0];
    for(int i =1; i<n; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }
    while(m--)
    {
        int from, to;
        cin >> from >> to;
        cout << sum[to-1] - sum[from-2] << '\n';
    }
    return 0;
}