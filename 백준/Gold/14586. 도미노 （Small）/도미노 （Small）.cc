#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,ll> > vll;

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) (x).begin(),(x).end()

const ll LLINF = 1e18;

int Left[301];
int Right[301];
vll v;

int findLeft(int here){

    int &ret = Left[here];
    if(ret!=-1) return  ret;

    ll a = v[here].first;
    ll b = v[here].second;

    int idx = lower_bound(all(v),mp(a-b, 0ll))-v.begin();

    
    ret = idx;
    for(;idx<here;idx++) ret = min(ret, findLeft(idx));
    return ret;
    
    
//    for(int i = idx; i < cur; i++) {
//        ret = min(ret, findLeft(i));
//    }
//    return ret;
}

int findRight(int here){

    int &ret = Right[here];
    if(ret!=-1) return  ret;

    ll a = v[here].first;
    ll b = v[here].second;

    int t = upper_bound(all(v),mp(a+b,LLINF))-v.begin();

    ret = t-1;
    for(;here<t;here++) ret = max(ret, findRight(here));
    return ret;
}

int dp[301][301];
int func(int a, int b){

    int &ret= dp[a][b];

    if(ret!=-1) return ret;

    if(a>b) return ret=0;
    if(Right[a]>=b||Left[b]<=a) return ret=1;
    
    ret=1e9;
    for(int i=a;i<=b;i++)
        ret = min(ret, func(a,Left[i]-1)+func(Left[i],Right[i])+func(Right[i]+1,b));
    return ret;
}

int main(){

    int n;
    scanf("%d",&n);

    memset(dp,-1,sizeof(dp));

    v.resize(n);
    ll a,b;
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a,&b);
        v[i] = mp(a,b);
    }
    sort(all(v));

    memset(Left,-1,sizeof(Left));
    memset(Right,-1,sizeof(Right));

    for(int i=0;i<n;i++){
        findLeft(i);
        findRight(i);
    }

    printf("%d\n", func(0,n-1));
    return 0;
}