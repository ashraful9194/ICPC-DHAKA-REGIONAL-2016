
#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
///DSU--all Subarrays,construct tree/connected component,queries.........
int par[1000002];
int spf[1000002];
int vis[1000002];
void sieve(int n)
{
    spf[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(spf[i]) continue;
        for(int j=i*i; j<=n; j+=i)
        {
            if(spf[j]) continue;
            spf[j]=i;
        }
    }
    for(int i=2; i<=n; i++) if(!spf[i]) spf[i]=i;
}
int find_par(int node)
{
    if(node==par[node]) return node;
    else return par[node]=find_par(par[node]);
}
void merge(int a,int b)
{
    a=find_par(a);
    b=find_par(b);
    if(a==b) return;
    par[a]=b;
}
int32_t main()
{
    ///complexity = O(1e6+nlogn).............
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     sieve(1000000);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
         int n;
         cin>>n;
         int a[n+5];
         int ans=0;
         for(int i=1; i<=1000000; i++)
         {
             vis[i]=0;
             par[i]=i;
         }
         for(int i=1; i<=n; i++)
         {
             cin>>a[i];
             int x=a[i];
             if(x==1)
             {
                 ++ans;
                 continue;
             }
             while(x>1)
             {
                 merge(a[i],spf[x]);
                 x=x/spf[x];
             }
         }
         for(int i=1; i<=n; i++)
         {
             if(a[i]==1) continue;
             int x=find_par(a[i]);
             if(vis[x]) continue;
             ++ans;
             vis[x]=1;
         }
         cout<<"Case "<<tc<<": ";
         cout<<ans<<endl;
     }


}
