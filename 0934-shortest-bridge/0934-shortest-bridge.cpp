class Solution {
public:
    int dy[4]={0,0,1,-1};
    int dx[4]={1,-1,0,0};
    
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int n=grid.size();
        vis[r][c]=1;
        grid[r][c]=2;
        for(int k=0;k<4;k++){
            int y=r+dy[k];
            int x=c+dx[k];
            if(y<0 || y>=n) continue;
            if(x<0 || x>=n) continue;
            if(vis[y][x]) continue;
            if(grid[y][x]==1) dfs(y,x,grid,vis);

        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
      int n=grid.size();
      vector<vector<bool>>vis(n,vector<bool>(n,0));
      int ok=0;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]==1){
                  dfs(i,j,grid,vis);
                  ok=1;
                  break;
              }
          }
          if(ok==1) break;
      }
      queue<int>q;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]==2){
                  q.push(i*n+j);
              }
          }
      }
      while(!q.empty()){
            int sz=q.size();
            while(sz--){
                 int node=q.front();
                 q.pop();
                 for(int k=0;k<4;k++){
                     int r=node/n+dy[k];
                     int c=node%n+dx[k];
                     if(r<0 || r>=n) continue;
                     if(c<0 || c>=n) continue;
                     if(grid[r][c]==1){
                         return grid[node/n][node%n]-2;
                     }
                     if(grid[r][c]==0){
                         grid[r][c]=grid[node/n][node%n]+1;
                         q.push(r*n+c);
                     }
                 } 
            }      
      }
      return -1;
    }
};