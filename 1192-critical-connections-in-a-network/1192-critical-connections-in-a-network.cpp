class Solution {
public:
    vector<vector<int>> graph,ans;
  
    vector<int> v;
    vector<int>time;
    vector<int>low;
    vector<bool>vis;
    int t=0;
    void dfs(int root,int par){
        vis[root]=true;
        time[root]=t;
        low[root]=t;
        t++;
        for(auto i:graph[root]){
           if(i==par) continue;
           if(!vis[i]){    
               dfs(i,root);
               v[0]=root;
               v[1]=i;
               if(time[root]<low[i]) ans.push_back(v);
               low[root]=min(low[root],low[i]);
           }
           else{
               low[root]=min(low[root],low[i]);
           }
        
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cns) {
        graph=vector<vector<int>>(n);
        time=vector<int>(n,-1);
        low=vector<int>(n,0);
        v=vector<int>(2,0);
        vis=vector<bool>(n,0);

        for(int i=0;i<cns.size();i++){
            graph[cns[i][0]].push_back(cns[i][1]);
            graph[cns[i][1]].push_back(cns[i][0]);
        }
        dfs(0,-1);
        return ans;
    }
};