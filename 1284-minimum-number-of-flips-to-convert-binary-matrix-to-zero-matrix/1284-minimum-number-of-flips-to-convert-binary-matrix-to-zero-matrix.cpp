class Solution {
public:
    vector<int>dp;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    // int rec(int mask,int nodes,int n,int m){
    //     for(int i=0; i<nodes;i++){
    //         int nw_mask=mask;
    //         nw_mask^=(1<<i);
    //         for(int k=0;k<4;k++){
    //             int y=i/m+dy[k];
    //             int x=i%m+dx[k];
    //             if(y<0 || y>=n) continue;
    //             if(x<0 || x>=m) continue;
    //             int node=y*m+x;
    //             nw_mask^=(1<<node);
    //             rec(nw_mask,nodes,n,m);
    //         }
    //     }
    // }
    int minFlips(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int nodes=n*m;
        dp=vector<int>((1<<nodes),-1);
        int curr_mask=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int node=i*m+j;
                if(mat[i][j]==1) curr_mask^=(1<<node);
            }
        }
        //rec(curr_mask,nodes,n,m);
        queue<int>q;
        q.push(curr_mask);
        int level=0;
        if(curr_mask==0) return 0;
        vector<bool>vis((1<<nodes),0);
        while(!q.empty()){
            int len=q.size();
            level++;
            while(len--){
                int mask=q.front();
                cout<<mask<<endl;
                vis[mask]=1;
                if(mask==0) return level-1;
                q.pop();
                for(int i=0; i<nodes;i++){
                    int nw_mask=mask;
                    nw_mask^=(1<<i);
                    for(int k=0;k<4;k++){
                        int y=i/m+dy[k];
                        int x=i%m+dx[k];
                        if(y<0 || y>=n) continue;
                        if(x<0 || x>=m) continue;
                        int node=y*m+x;
                        nw_mask^=(1<<node);
                    }
                    if(!vis[nw_mask]) q.push(nw_mask);
                }
            }
        }
        return -1;
    }
};