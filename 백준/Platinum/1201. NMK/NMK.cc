#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k; // 증가(= 그룹의 개수) 감소(=그룹중 가장 긴 그룹의 길이)
    if(m+k-1 <=n && n <= m*k)
    {
        vector <int> a(n);
        for(int i = 0; i<n; i++)
        {
            a[i] = i +1;
        }
        vector <int> g; // 그룹 경계 저장할 곳.
        n -= k;
        m--;
        g.push_back(0);
        g.push_back(k);
        int gs = m==0 ? 1 : n/m; //m 즉 만들어야 하는 그룹의 개수가 더이상 없다면, 
        int r = m==0 ? 0 : n%m;  // 삼항연산자로 처리한 이유가 m이 0이면 '/'과 '%' 연산이 불가능하기때문.
        // 만들어야 하는 그룹의 개수가 더이상 없을 경우, 
        for(int i =0; i< m; i++)
        {
            g.push_back(g.back()+gs+(r==0 ? 0 : 1));
            if(r>0)
                r--;
        }

        for(int i =0; i<g.size()-1; i++)
            reverse(a.begin()+g[i], a.begin()+g[i+1]);
        for(int i = 0; i<a.size(); i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    else
        cout << -1 << '\n';
    return 0;
}