#include <bits/stdc++.h>
using namespace std;
vector<string> answer;
bool dfs(string start, vector<vector<string>> &tickets, vector<bool> &check, int cnt) {
    answer.push_back(start);
    if(cnt == tickets.size()) return true;
    for(int i = 0; i<tickets.size(); i++) {
        if(tickets[i][0] == start && check[i]==false) {
            check[i] = true;
            if(dfs(tickets[i][1], tickets, check, cnt+1)) return true;
            check[i] = false;
        }
    }
    answer.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> check(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, check, 0);
    return answer;
}