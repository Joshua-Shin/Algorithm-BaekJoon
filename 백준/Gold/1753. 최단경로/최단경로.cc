#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector <pair<int, int> > adj[20001]; // 정점, 가중치
vector<int> dijkstra(int start)
{
    priority_queue <pair<int, int>> pq; // -비용 정점
    vector <int> dist(n+1, 2e9); // 이걸 전역변수로 선언할 수 없는게, n 때문에 그럼. n의 값이 main 함수에서 입력을 받아서 수가 생기는건데, 입력을 받기전에 전역으로 초기화를 해버리면 n 값이 0일때 초기화가 되는거잖아.
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        int x = pq.top().second;
        int xCost = -pq.top().first;
        pq.pop(); // 다익스트라에서는 여기에서 방문이 이루어진다고 봐야하는게 맞는듯.
        if(xCost > dist[x]) continue; 
        for(int i =0; i<adj[x].size(); i++)
        {
            int nx = adj[x][i].first;
            int nxCost = xCost + adj[x][i].second;
            if(nxCost < dist[nx])
            {
                dist[nx] = nxCost;
                pq.push({-nxCost, nx});
            }
        }
    }
    return dist;
}

int main()
{
    cin >> n >> m;
    int start;
    cin >> start;
    for(int i =0; i<m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        adj[from].push_back({to, w});
    }
    vector<int> dist = dijkstra(start);
    for(int i =1; i<n+1; i++)
    {
        if(dist[i]!=2e9)
            cout << dist[i] << '\n';
        else
            cout << "INF" << '\n';
    }
    return 0;
}