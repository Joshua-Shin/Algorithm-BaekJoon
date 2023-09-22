#include <iostream>
using namespace std;
char map[10][10];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int answer = 11;
void go (int rx, int ry, int bx, int by, int cnt, int dir)
{
    if(cnt>=11)
        return;
    int nrx = rx + dx[dir];
    int nry = ry + dy[dir];
    int nbx = bx + dx[dir];
    int nby = by + dy[dir];
    bool red_suc = false;
    bool blue_suc = false;

    while(1)
    {
        if(map[nrx][nry]=='#')
            break;
        else if(map[nrx][nry]=='O')
        {
            red_suc = true;
            break;
        }
        nrx += dx[dir];
        nry += dy[dir];
    }
    nrx -= dx[dir];
    nry -= dy[dir];

    while(1)
    {
        if(map[nbx][nby]=='#')
            break;
        else if(map[nbx][nby]=='O')
        {
            blue_suc = true;
            break;
        }
        nbx += dx[dir];
        nby += dy[dir];
    }
    nbx -= dx[dir];
    nby -= dy[dir];

    if(blue_suc)
        return;
    else if(red_suc) // 파란공은 안빠졌으나, 빨간공은 빠졌을때.
        answer = min(answer, cnt);

    // 아래서부터는 아직 둘 다 안빠졌고 벽에서 멈춘경우.
    if(nrx==nbx && nry == nby) // 둘다 겹쳐있다면, 많이 이동한 애를 뒤로 물어야함
    {
        int red_dis = abs(rx - nrx) + abs(ry - nry);
        int blue_dis = abs(bx - nbx) + abs(by - nby);
        if(red_dis > blue_dis)
        {
            nrx -= dx[dir];
            nry -= dy[dir];
        }
        else
        {
            nbx -= dx[dir];
            nby -= dy[dir];
        }
    }
    // 이제 다른 방향으로 이동
    for(int i =0; i<4; i++)
    {
        if(i==dir) continue;
        if((i+dir)%2 == 0) continue;
        go(nrx, nry, nbx, nby, cnt+1, i);
    }

}

int main()
{
    int n, m;
    cin >> n >> m; // 세로길이, 가로 길이
    int rx, ry, bx, by, hx, hy;
    for(int i =0; i<n; i++)
        for(int j =0; j<m; j++)
        {
            cin >> map[i][j];
            if(map[i][j]=='R')
            {
                rx = i;
                ry = j;
            }
            else if(map[i][j]=='B')
            {
                bx = i;
                by = j;
            }
            else if(map[i][j]=='O')
            {
                hx = i;
                hy = j;
            }
        }
    for(int i =0; i<4; i++)
    {
        // 뭔가 초기화를 해줬던것 같은데 할 필요가 있는건가??
        go(rx, ry, bx, by, 1, i); 
    }


    if(answer== 11)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}