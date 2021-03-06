    #include<bits/stdc++.h>
    #define bst           ios_base::sync_with_stdio(0);
    #define bug(x)        cerr<<#x<<'='<<x<<endl;
    #define lp(i,a,b)     for(int i=a; i<=b; i++)
    #define ll            long long int
    #define pb            emplace_back
    using namespace std;
     
    const int nax = 3e4 + 9 ;
    vector<long long> arr[nax]={};
    //vector< vector<long long int > > arr(nax, vector<ll>(5)) ;
    vector<long long> tree[30009];
    vector<long long> weight[30009];
    long long siz[30009];
    long long dfs(ll pathabo, ll dhoro, bool v[]){
        v[pathabo]=true;
        ll mx=dhoro;
        for(int i=0; i<tree[pathabo].size(); i++){;
            if(v[tree[pathabo][i]]==false){
                if(siz[pathabo]<3){
                    ll k=dfs(tree[pathabo][i], weight[pathabo][i], v);
                    arr[pathabo].pb(k);
                    siz[pathabo]++;
                    mx=max(mx, k+dhoro);
                }
                else{
                    ll k=dfs(tree[pathabo][i], weight[pathabo][i], v);
                    arr[pathabo][2]=k;
                    mx=max(mx, k+dhoro);
                }
                sort(arr[pathabo].begin(), arr[pathabo].end());
                reverse(arr[pathabo].begin(), arr[pathabo].end());
            }
        }
        return mx;
    }
    long long add(ll pathabo, ll boro, ll chuto, bool kv[]){
        kv[pathabo]=true;
        for(ll i=0; i<tree[pathabo].size(); i++){
            if(kv[tree[pathabo][i]]==false){
                ll k=tree[pathabo][i];
                if(siz[k]>0){
       // cout<<pathabo<<' '<<tree[pathabo][i]<<' '<<arr[pathabo][0]<<endl;
                    ll w=weight[pathabo][i];
                    if(arr[k][0]+w==boro){
                        if(siz[k]<3){
                            arr[k].pb(chuto+w);
                            siz[k]++;
                        }
                        else arr[k][2]=chuto+w;
                        sort(arr[k].begin(), arr[k].end());
                        reverse(arr[k].begin(), arr[k].end());
                    }
                    else{
                        if(siz[k]<3){
                                arr[k].pb(boro+w);
                                siz[k]++;
                        }
                        else arr[k][2]=boro+w;
                        sort(arr[k].begin(), arr[k].end());
                        reverse(arr[k].begin(), arr[k].end());
                    }
                }
                else if(siz[k]==0){
                    ll w=weight[pathabo][i];
                    if(w==boro){
                        if(siz[k]<3){
                            arr[k].pb(w+chuto);
                            siz[k]++;
                        }
                        else arr[k][2]=w+chuto;
                        sort(arr[k].begin(), arr[k].end());
                        reverse(arr[k].begin(), arr[k].end());
                    }
                    else{
                        if(siz[k]<3){
                                arr[k].pb(boro+w);
                                siz[k]++;
                        }
                        else arr[k][2]=boro+w;
                        sort(arr[k].begin(), arr[k].end());
                        reverse(arr[k].begin(), arr[k].end());
                    }
                    //cout <<arr[k][0] << endl ;
                    sort(arr[k].begin(), arr[k].end());
                    reverse(arr[k].begin(), arr[k].end());
                    //puts("done") ;
                }
              //  cout<<boro<<'\t'<<weight[pathabo][i]<<endl;
             //   cout<<k<<' '<<arr[k][0]<<endl;
                long long x, y;
                x=arr[k][0];
                if(siz[k]>1) y=arr[tree[pathabo][i]][1];
                else y=0;
                add(tree[pathabo][i], x, y, kv);
            }
        }
    }
    int main(){
        ll t, tc=1, n, i, j, k;
        cin>>t;
        while(t--){
            scanf("%lld", &n);
            ll u, v,w;
            ll pathabo;
            for(i=0; i<n; i++){
                tree[i].clear();
                weight[i].clear();
            }
            for(i=0; i<n; i++) arr[i].clear();
            for(i=0; i<n-1; i++){
                scanf("%lld %lld %lld", &u, &v, &w);
                if(i==0) pathabo=u;
                tree[u].pb(v);
                tree[v].pb(u);
                weight[u].pb(w);
                weight[v].pb(w);
            }
            if(i==1){
                printf("Case %lld: %lld\n", tc++, w);
                continue;
            }
            else if(i==0){
                printf("Case %lld: 0\n", tc++);
                continue;
            }
            bool iv[n+1]={};
            for(i=0; i<=n; i++) siz[i]=0;
            k=dfs(pathabo, 0, iv);
            bool kv[n+1]={};
            ll x, y=0;
            x=arr[pathabo][0];
            if(arr[pathabo].size()>1) y=arr[pathabo][1];
            add(pathabo, x, y, kv);
            ll ans=0;
            printf("Case %lld:\n", tc++);
            for(i=0; i<n; i++){
                printf("%lld\n", arr[i][0]);
            }
        }
        return 0;
    }
