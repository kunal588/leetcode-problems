class Solution {
public:
    vector<vector<int>>graph;
    vector<bool>vis;
    int cnt=0;
    int dy[4]={0,0,1,-1};
    int dx[4]={1,-1,0,0};
    void dfs(int y,int x,int n,int m,vector<vector<int>>& grid){
        vis[y*m+x]=1;
        for(int k=0;k<4;k++){
            int r=y+dy[k];
            int c=x+dx[k];
            if(r<0 || r>=n) continue;
            if(c<0 || c>=m) continue;
            if(vis[r*m+c]) continue;
            if(grid[r][c]==0) continue;
            dfs(r,c,n,m,grid);
       }
    }
    // articulation point
    vector<int>dis,low;
    int time=0;
    void dfs1(int node,int par){
        cout<<node<<endl;
        int childs=0;
        vis[node]=1;
        dis[node]=low[node]=time;
        time++;
        for(auto child:graph[node]){
            if(child==par) continue;
            if(!vis[child]){
                childs++;
                dfs1(child,node);
                low[node]=min(low[node],low[child]);
                if(low[child]>=dis[node] && par!=-1){
                    cout<<child<<node<<endl;
                     cnt++;
                }
            }
            else{
                low[node]=min(low[node],dis[child]);
            }
        }
        if(childs>1 && par==-1){
            cnt++;
        } 
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        graph=vector<vector<int>>(n*m);
        vis=vector<bool>(n*m,0);        
        int ok=0;
        int node=-1;
        int nodes=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) nodes++;
                if(!vis[i*m+j] && grid[i][j]==1){
                     node=i*m+j;
                     if(ok==1) return 0;
                     dfs(i,j,n,m,grid);
                     ok=1;
                }
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int r=i+dy[k];
                    int c=j+dx[k];
                    if(r<0 || r>=n) continue;
                    if(c<0 || c>=m) continue;
                    if(grid[r][c]==0) continue;
                    graph[i*m+j].push_back(r*m+c);
                }
            }
        }
        vis=vector<bool>(n*m,0);
        dis=vector<int>(n*m,0);
        low=vector<int>(n*m,0);
        if(node==-1) return 0;
        if(nodes==1) return 1;
        dfs1(node,-1);
        if(cnt>0) return 1;
        return 2;
        
        
        
    }
};