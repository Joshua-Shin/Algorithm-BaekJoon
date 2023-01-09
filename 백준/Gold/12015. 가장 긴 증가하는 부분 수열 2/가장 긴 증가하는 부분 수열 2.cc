#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
vector<int> seq;
int n;
void lis() {
    seq.push_back(arr[0]);
    for(int i = 1; i<n; i++) {
        if(seq.back() < arr[i])
            seq.push_back(arr[i]);
        else {
            auto it =  lower_bound(seq.begin(), seq.end(), arr[i]);
            if(it == seq.end()) continue;
            seq[it-seq.begin()] = arr[i];
        } 
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    lis();
    cout << seq.size();
    return 0;
}