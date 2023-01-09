#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> v;
    for(int i =0; i<n; i++) {
        int temp;
        cin >> temp;
        auto iter = lower_bound(v.begin(), v.end(), temp);
        if(iter==v.end())
           v.push_back(temp);
        else
            (*iter) = temp; 
    }
    cout << v.size() << '\n';
    return 0;
}