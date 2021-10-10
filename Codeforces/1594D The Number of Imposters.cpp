// Solution using DSU + BFS(to check bipartitie nature of graph!)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long int ll;
typedef long double ld;
#define nl cout << "\n"
#define vc vector
#define mapll map<ll,ll>
#define setll set<ll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define loopf(i,a,b) for(ll i=a;i<b;i++)
#define loopb(i,b,a) for(ll i=a-1;i>=b;i--)
#define rep(i,a,b,x) for(ll i=a;i<b;i+=x)
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,ll>> vpl;
#define read(v) for(int i=0;i<(int)v.size();++i) cin>>v[i]
#define read1(v) for(int i=1;i<(int)v.size();++i) cin>>v[i]
#define print(v) {for(int i=0;i<(int)v.size();++i)cout<<v[i]<<" ";nl;}
#define print1(v) {for(int i=1;i<(int)v.size();++i)cout<<v[i]<<" ";nl;}
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define ANS cout<<ans<<endl
#define ub upper_bound
#define lb lower_bound
#define max_heap priority_queue<ll>
#define min_heap priority_queue<ll, vector<ll>, greater<ll>>
#define max_heap_pl priority_queue<pl>
#define min_heap_pl priority_queue<pl, vector<pl>, greater<pl>>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umapll unordered_map<ll,ll,custom_hash>
//ll M=1e9+7;
 
vll p,sz;
ll get(ll a){
    return p[a] = (p[a]==a) ? a : get(p[a]);
}
void uni(ll a, ll b){
    a = get(a), b = get(b);
    if(sz[a]<sz[b]){
        p[a] = b;
        sz[b] += sz[a];
    }
    else{
        p[b] = a;
        sz[a] += sz[b];
    }
}
 
 
void solve();
int main() {
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);
 
ll t=1;
cin>>t;
while(t--){
    solve();
}
return 0;
}
 
void solve(){
    ll n,m; cin>>n>>m;
    vll edges[n+1];
    
    p.clear();
    sz.clear();
    p.resize(n+1);
    sz.resize(n+1,1);
    loopf(i,0,n+1)p[i]=i;
    
    while(m--){
        ll i,j; string c;
        cin>>i>>j>>c;
        if(c=="imposter"){edges[i].pb(j); edges[j].pb(i);}
        else {if(get(i)!=get(j))uni(i,j);}
    }
    
    if(n==1){cout<<"1\n"; return;}
    
    ll ans1=0,ans2=0,ans=0;
    vll ed[n+1];
    
    loopf(i,1,n+1){
        for(auto e:edges[i])if(get(i)==get(e)){cout<<"-1\n"; return;}
    }
    
    
    loopf(i,1,n+1){
        for(auto e:edges[i])ed[get(e)].pb(get(i)), ed[get(i)].pb(get(e));
    }
    
    vll vis(n+1,0);
    vll col(n+1,0);
    
    loopf(i,1,n+1){
        ll ii = i;
        i = get(i);
        if(!vis[i]){
            col[i]=1;
            ans1=0;ans2=0;
            queue<pl> q;
            vis[i]=1;
            q.push({i,0});
            while(!q.empty()){
                pl now = q.front(); q.pop();
                if(now.ss%2)ans1+=sz[now.ff];
                else ans2+=sz[now.ff];
                for(auto e:ed[now.ff]){
                    if(col[now.ff]==col[e]){cout<<"-1\n"; return;}
                    if(!vis[e]){
                        if(col[now.ff]==1)col[e]=2;
                        else col[e]=1;
                        vis[e]=1;
                        q.push({e,now.ss+1});
                    }
                }
            }
            ans += max(ans1,ans2);
        }
        i=ii;
    }
    cout<<ans;nl;
}