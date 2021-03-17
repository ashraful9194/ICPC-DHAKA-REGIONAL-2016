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

int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     for(int tc=1; tc<=t; tc++)
     {
          int n;
          cin>>n;
          map<int,int>cnt;
          for(int i=0; i<n; i++)
          {
              int x;
              cin>>x;
              ++cnt[x];
          }
          int now=0;
          vector<char>ans;
          int ok=1;
         for(int i=0; i<n; i++)
          {
              if(cnt[now+1])
              {
                  ++now;
                  --cnt[now];
                  ans.pb('(');
              }
              else if(now>0 && cnt[now-1])
              {
                  --now;
                  --cnt[now];
                  ans.pb(')');
              }
              else
              {
                  ok=0;
                  break;
              }
          }

         cout<<"Case "<<tc<<": ";
         if(!ok || now)
         {
             cout<<"invalid"<<endl;
             continue;
         }
         for(auto i:ans) cout<<i;
         cout<<endl;
     }

}

