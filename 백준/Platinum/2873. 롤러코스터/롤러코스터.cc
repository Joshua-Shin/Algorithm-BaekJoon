#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[1000][1000];
void append(string &s, char c, int cnt) // 반복문 계속 갈기는것보다 이거 참 현명하네.
{
    for (int i = 0; i < cnt; i++)
    {
        s += c;
    }
}
int main()
{
    int n, m;
    cin >> n >> m; // 세로 길이, 가로길이
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    string s = "";
    if (n % 2 == 1) // 세로 길이가 홀수라면, ㄹ 패턴
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                append(s, 'R', m - 1);
                if (i != n - 1)
                {
                    append(s, 'D', 1);
                }
            }
            else
            {
                append(s, 'L', m - 1);
                append(s, 'D', 1);
            }
        }
    }
    else if (m % 2 == 1) // 세로 길이는 짝수인데, 가로 길이가 홀수라면, 
    {
        for (int j = 0; j < m; j++)
        {
            if (j % 2 == 0)
            {
                append(s, 'D', n - 1);
                if (j != m - 1)
                {
                    append(s, 'R', 1);
                }
            }
            else
            {
                append(s, 'U', n - 1);
                append(s, 'R', 1);
            }
        }
    }
    /////////////////////////////////////////////여기까지는 나도 함.
    else // 세로 길이, 가로 길이 둘다 짝수 라면, 검정칸 중에 하나만 빼면 도달할 수 있다라는 증명은,, 강의 다시 봐봐
    {
        int x, y; // 제거해야 할 x y 찾기.  // 
        x = 0;
        y = 1; // 체스판으로 볼때, x y 를 첫 검정칸으로 일단 초기화 해준거고. 쭉 for문으로 전체 검정칸 훑으면서 가장 최소값 찾는거임.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    if (a[x][y] > a[i][j])
                    {
                        x = i;
                        y = j;
                    }
                }
            }
        } //빼야될 x, y 찾았어.
        ////////////////////////
        int x1 = 0;
        int y1 = 0; // 시작점
        int x2 = n - 1;
        int y2 = m - 1; // 도착점
        string s2 = "";
        while (x2 - x1 > 1) // 시작점과 도착점의 높이차가 1일때까지 반복 시키는거네
        {
            if (x1 / 2 < x / 2) // 빠트릴 칸이 시작점보다 아래줄에 있을경우. 2로 나눈 이유는 2줄씩 가기 위해서. 
            {
                append(s, 'R', m - 1);
                append(s, 'D', 1);
                append(s, 'L', m - 1);
                append(s, 'D', 1);
                x1 += 2;
            }
            if (x / 2 < x2 / 2) // 빠트릴 칸이 도착점보다 윗줄에 있을 경우. 도착점이 와리가리하면서 거꾸로 위로 올라가는 개념
            {
                append(s2, 'R', m - 1);                    
                append(s2, 'D', 1);
                append(s2, 'L', m - 1);
                append(s2, 'D', 1);
                
                /* 이렇게 해놓은다음에 나중에 s2를 안뒤집으면 되긴 함. 아니.. 아니지.. 
                append(s2, 'D', 1);                    
                append(s2, 'L', m - 1);
                append(s2, 'D', 1);
                append(s2, 'R', m - 1);
                */
                x2 -= 2;
            }
        }
        while (y2 - y1 > 1) // 시작점과 도착점의 가로차가 1일때까지 반복
        {
            if (y1 / 2 < y / 2) // 빠트릴 칸의 열이 시작점의 열보다 오른쪽에 있을때.
            {
                append(s, 'D', 1);
                append(s, 'R', 1);
                append(s, 'U', 1);
                append(s, 'R', 1);
                y1 += 2;
            }
            if (y / 2 < y2 / 2) // 빠트릴 칸의 열이 도착점의 열보다 왼쪽에 있을때.
            {
                append(s2, 'D', 1);
                append(s2, 'R', 1);
                append(s2, 'U', 1);
                append(s2, 'R', 1);
                /*
                append(s2, 'R', 1);
                append(s2, 'U', 1);
                append(s2, 'R', 1);
                append(s2, 'D', 1);
                */
                y2 -= 2;
            }
        }
        ///////////////////////// 2*2 로 줄임.
        if (y == y1)       // 빠트릴 칸이 시작점 바로 아래칸에 있을 경우
        {
            append(s, 'R', 1);
            append(s, 'D', 1);
        }
        else // 빠트릴 칸이 도착점 바로 위칸에 있을 경우
        {
            append(s, 'D', 1);
            append(s, 'R', 1);
        }
        reverse(s2.begin(), s2.end());
        s += s2;
    }
    cout << s << '\n';
    return 0;
}