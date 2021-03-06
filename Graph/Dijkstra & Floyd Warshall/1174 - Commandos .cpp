#include<bits/stdc++.h>
#define bst           ios_base::sync_with_stdio(0);
#define bug(x)        cerr<<#x<<'='<<x<<endl;
#define lp(i,a,b)     for(int i=a; i<=b; i++)
#define ll            long long int
#define pb            emplace_back
using namespace std;
vector<ll> node[105];
long long bfs(ll src, ll dest, ll num){
    bool isvisited[num]={};   // every node is false now
    queue <ll> connected;
    connected.push(src);
    connected.push(500);     // to divide all level from the previous...level is the distance from src to dest
    ll length=0;
    isvisited[src]=true;
    while(!connected.empty()){
        ll x=connected.front(), i=0;
        if(x==500){
            connected.pop();
            connected.push(500);
            length++;          // 1 level increased
            continue;
        }
        else if(x==dest){
            break;
        }
        for(i=0; i<node[x].size(); i++){
            ll n=node[x][i];
            if(isvisited[n]==false){
                isvisited[n]=true;
                connected.push(n);
            }
        }
        connected.pop();
    }
    return length;
}
int main(){
    ll t, tc=1, i , j, k;
    cin>>t;
    while(t--){
        ll n, r;
        scanf("%lld %lld", &n, &r);
        for(i=0; i<=n; i++) node[i].clear();
        for(i=0; i<r; i++){
            ll u, v;
            scanf("%lld %lld", &u, &v);
            node[u].pb(v);
            node[v].pb(u);
        }
        ll src, dest;
        scanf("%lld %lld", &src, &dest);
        ll ans=0;
        for(i=0; i<n; i++){
            ans=max(bfs(i, src, n)+bfs(i, dest, n), ans);    // distance from a node to src+ distance from a node to dest
        }
        printf("Case %lld: %lld\n", tc++, ans);
    }
    return 0;
}
