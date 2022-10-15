#define N 200002
#define M 1000000007
#define fitr(i,a,b) for(auto i=a;i<b;i++)
#define ritr(i,a,b) for(auto i=b;i>=a;i--)
#define print(a) cout<<a<<endl
#define pb(a) push_back(a)
#define rangeitr(a) a.begin(),a.end()
#define pii pair<int,int>
#define ll long long int 
#define ld long double 


class Solution {
public:
    vector<vector<int>>graph;
    int sz[N];
    int dfs(int node){
       int size=1;
       for(auto child:graph[node]){
            size+=dfs(child);
       }
       return sz[node]=size;
    }
    
    int binpow(int a,int b){
        if(a==0) return 0;
        int res=1;
        while(b){
            if(b%2) res=(1ll*res*a)%M;
            b/=2;
            a=(1ll*a*a)%M;
        }
        return res;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n=prevRoom.size();
        graph=vector<vector<int>>(n);
        fitr(i,0,n){
             if(prevRoom[i]!=-1){
                  graph[prevRoom[i]].pb(i);
             } 
        }
        dfs(0); 
        int ans=1;
        fitr(i,1,n+1) ans=(1ll*ans*i)%M;
        fitr(i,0,n){
            ans=(1ll*ans*binpow(sz[i],M-2))%M;
        }
        return ans;
    }
};