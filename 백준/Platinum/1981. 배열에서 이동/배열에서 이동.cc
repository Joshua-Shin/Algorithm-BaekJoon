#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int n;
int map[100][100];
bool c[100][100];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool bfs(int mn, int mx) // 아.. min과 max를 변수로 쓸떄는 mn mx라 하는구나..
{
    if(map[0][0] < mn || map[0][0] > mx)
        return false;
    memset(c, false, sizeof(c));
    queue <pair<int, int>> q;
    c[0][0] = true;
    q.push(make_pair(0, 0));
    while(!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int k=0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0<= nx && nx <n && 0<= ny && ny < n)
            {
                if(c[nx][ny]==false)
                {
                    if(mn <= map[nx][ny] && map[nx][ny] <= mx)
                    {
                        c[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    return c[n-1][n-1];
}

bool go(int mid)
{
    for(int mn = 0; mn + mid <=200; mn++)
    {
        if(bfs(mn, mn+mid))
            return true;
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i =0; i<n; i++)
        for(int j =0; j<n; j++)
            cin >> map[i][j];
    int left = 0;
    int right = 200;
    int ans;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(go(mid))
        {
            right = mid -1;
            ans = mid;
        }
        else
            left = mid +1;
    }
    cout << ans << '\n';
    return 0;
}