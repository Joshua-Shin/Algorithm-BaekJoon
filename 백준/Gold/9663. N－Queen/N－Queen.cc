#include <iostream>
using namespace std;
int n;
int ans;
bool c[15][15];
//int s[15][15];

bool check (int row, int col)
{
    for(int i = 0; i< row ; i++)
        if(c[i][col])
            return false;

    // \ 검사
    int x = row -1;
    int y = col -1;
    while(x>=0 && y>=0)
    {
        if(c[x][y])
            return false;
        x--;
        y--;
    }
    // / 검사
    x = row -1;
    y = col +1;
    while (x>=0 && y<n)
    {
        if(c[x][y])
            return false;
        x--;
        y++;
    }

    return true;
}

void sel(int row)
{
    if(row==n)
    {
        ans++;
        return;
    }

    for(int col = 0; col<n; col++)
    {
        if(c[row][col]==false && check(row, col)==true)
        {
            c[row][col] = true;
            sel(row+1);
            c[row][col] = false;
        }

    }


}

int main()
{
    cin >> n;
    sel(0);
    cout << ans << '\n';
    return 0;
}