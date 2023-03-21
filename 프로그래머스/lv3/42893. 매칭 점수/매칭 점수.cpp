#include <bits/stdc++.h>
using namespace std;
// 각 페이지마다 기본점수, 외부링크수를 배열에 갱신. 인접리스트도 두어야겠네. 링크점수는 파생속성이니 일단 두고.
// pair로 링크점수, 페이지인덱스 기록해서 vector에 저장한다음에 정렬. 링크점수 desc, 페이지 asc
vector<int> adj[21];
int primeScore[21];
double linkScore[21];
int cntLink[21];
map<string, int> urlIdx;
vector<pair<double, int>> ans;
string findSiteUrl(string &page) {
    string patten = "<meta property=\"og:url\" content=\"";
    int start = page.find(patten) + patten.size();
    int end = page.find("\"/>", start);
    return page.substr(start, end-start);
}

int findCnt(string &page, string &word) {
    int cnt = 0;
    for(int i = 0; i < page.size(); i++) {
        if(i != 0 && ('a' <= page[i-1] && page[i-1] <= 'z')) continue;
        if(page[i]!=word[0]) continue;
        bool flag = false;
        for(int j = 1; j < word.size(); j++) {
            if(i + j >= page.size() || page[i+j] != word[j]) {
                flag = true; // 실패
                break;
            }
            if(j == word.size()-1 && i+j+1 < page.size() && ('a' <= page[i+j+1] && page[i+j+1] <= 'z'))
                flag = true;
        }
        if(!flag) cnt++;
    }
    return cnt;
}
vector<int> analLink(string &page) {
    vector<int> ret;
    // <a href="https://careers.kakao.com/index">
    int start = 0, end = 0;
    while(1) {
        string patten = "<a href=\"";
        int temp = page.find(patten, start);
        if(temp == -1) break;
        start = temp + patten.size();
        end = page.find("\">", start);
        string str = page.substr(start, end-start);
        if(urlIdx.find(str)==urlIdx.end())
            ret.push_back(-1);
        else ret.push_back(urlIdx[str]);
        start = end;
    }
    return ret;
}
bool cmp(pair<double, int> a, pair<double, int> b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
} 
int solution(string word, vector<string> pages) {
    // 페이지 소문자로 변환. ok
    for(auto &page: pages) {
        for(int i = 0; i < page.size(); i++) {
            if('A' <= page[i] && page[i] <= 'Z')
                page[i] = tolower(page[i]);
        }
    }
    // 단어 소문자로 변환. ok
    for(int i = 0; i < word.size(); i++) {
        if('A' <= word[i] && word[i] <= 'Z')
            word[i] = tolower(word[i]);
    }

    // url 매핑, 기본점수
    int idx = 0;
    for(auto page: pages) {
        urlIdx[findSiteUrl(page)] = idx;
        primeScore[idx++] = findCnt(page, word);
    }
    idx = 0;
    for(auto page: pages) {
        vector<int> link = analLink(page);
        cntLink[idx] = link.size(); // 내가 가지고 있는 외부 링크 수
        for(auto x: link) {
            if(x==-1) continue;
            adj[x].push_back(idx); // 나한테서 나가는 외부 링크
        }
        idx++;
    }
    // 각 페이지마다 링크점수 갱신해놓기 
    for(int i = 0; i < pages.size(); i++) {
        if(cntLink[i]==0) continue;
        linkScore[i] = (double)primeScore[i] / cntLink[i]; // 이건 괜찮. 
    }
    for(int i = 0; i < pages.size(); i++) {
        double score = primeScore[i];
        for(auto nIdx: adj[i]) score += linkScore[nIdx]; // 이게 잘못
        ans.push_back({score, i});
    }
    sort(ans.begin(), ans.end(), cmp);
    // for(auto x: ans) {
    //     cout << x.first << ' ' <<x.second << '\n'; // 최종점수, 페이지인덱스
    // }
    return ans[0].second;
}