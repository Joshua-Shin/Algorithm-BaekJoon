#include <iostream>
using namespace std;
struct Node
{
    int left, right;
    int level, order;
};
Node a[10001];
int cnt[10001];
int col = 0;
int maxleft[10001];
int maxright[10001];
void inorder(int node, int depth)
{
    if(node==-1)
        return;
    inorder(a[node].left, depth+1);
    a[node].level = depth;
    a[node].order = (++col);
    inorder(a[node].right, depth+1);
}
int main()
{
    int n;
    cin >> n; //19
    for(int i =0; i<n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].left = y;
        a[x].right = z;
        if(y!=-1) cnt[y] += 1;
        if(z!=-1) cnt[z] += 1;
    }// 입력완료
    int root = 0;
    for(int i=1; i<=n; i++)
    {
        if(cnt[i]==0)
            root = i;
    }// 루트노드 설정완료
    inorder(root, 1);
    // 각 노드에다가 행 열 숫자 저장 완료
    int maxdepth =0;
    for(int i=1; i<=n; i++)
    {
        int order = a[i].order;
        int level = a[i].level;
        if(maxleft[level]==0)
        {
            maxleft[level] = order;
        }
        else
        {
            maxleft[level] = min(order, maxleft[level]);
        }
        maxright[level] = max(maxright[level], order);
        maxdepth = max(maxdepth, level);
    }// 가장 최고 레벨 저장, 레벨을 인덱스로 하여 가장 왼쪽에 있는열, 가장 오른쪽에 있는열 저장.
    int ans = 0;
    int anslev = 0;
    for(int i =1; i<= maxdepth; i++)
    {
        if(ans < maxright[i]-maxleft[i]+1)
        {
            ans = maxright[i]-maxleft[i]+1;
            anslev = i;
        }
    }
    cout << anslev << ' ' << ans << '\n';
    return 0;
}