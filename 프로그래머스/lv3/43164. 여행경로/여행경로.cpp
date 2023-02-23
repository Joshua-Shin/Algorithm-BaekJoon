#include <bits/stdc++.h>
using namespace std;
vector<bool> check;
vector<string> answer;
vector<vector<string>> tickets;
bool dfs(string start, int cnt) {
    answer.push_back(start);
    if(cnt == tickets.size()) return true;
    for(int i = 0; i<tickets.size(); i++) {
        if(tickets[i][0] != start) continue;
        if(check[i]) continue;
        check[i] = true;
        if(dfs(tickets[i][1], cnt + 1)) return true;
        check[i] = false;
    }
    answer.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    check.resize(tickets.size());
    sort(tickets.begin(), tickets.end());
    ::tickets = tickets;
    dfs("ICN", 0);
    return answer;
}