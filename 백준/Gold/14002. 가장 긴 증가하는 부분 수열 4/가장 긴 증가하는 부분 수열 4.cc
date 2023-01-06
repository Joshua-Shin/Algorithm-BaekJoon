#include <iostream>
using namespace std;
int a[1000], d[1000], v[1000], ans, p, n, i, j;
void go(int p){
    if (p == -1)
        return;
    go(v[p]);
    cout << a[p] << ' ';
}
int main(){
    cin >> n;
    for (; i < n; i++){
        cin >> a[i];
        d[i] = 1;
        v[i] = -1;
        for(j=0;j<i; j++){
            if(a[j] <a[i] && d[i] < d[j] +1){
                d[i] = d[j] +1;
                v[i] = j;
            }
        }
        if(ans < d[i]){
            ans = d[i];
            p =i;
        }
    }
    cout << ans << '\n';
    go(p);
    return 0;
}