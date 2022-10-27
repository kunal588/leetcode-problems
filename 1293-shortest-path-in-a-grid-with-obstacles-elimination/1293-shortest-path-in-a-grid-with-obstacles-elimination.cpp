class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<int,int>>q;
        q.push({0,grid[0][0]});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n*m,vector<int>(k+1,-1));
        vis[0][grid[0][0]]=1;
        if(grid[0][0]<=k && n*m==1){
            return 0;
        }
        int len=0;
        while(!q.empty()){
            int sz=q.size();
            len++;
            while(sz--){
                int node,used;
                tie(node,used)=q.front();
                q.pop();
                for(int t=0;t<4;t++){
                    int y=node/m+dy[t];
                    int x=node%m+dx[t];
                    int nw_node=y*m+x;
                    if(y<0 || y>=n) continue;
                    if(x<0 || x>=m) continue;
                    if(used+grid[y][x]<=k && vis[nw_node][used+grid[y][x]]==-1){
                         if(nw_node==n*m-1){
                            return len;
                         }
                         vis[nw_node][used+grid[y][x]]=len;
                         q.push({nw_node,used+grid[y][x]});
                    } 
                }
                
            }
        }
        return -1;
        
    }
};