class Solution {
public:
    map<pair<vector<int>,int>,int>vis;
    int rec(int i,vector<int>& cookies,vector<int>kids,int n,int m){
        if(i==n){
            int mx=0;
            for(auto val:kids) mx=max(mx,val);
            return mx;
        }
        if(vis.find({kids,i})!=vis.end()) return vis[{kids,i}];
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            kids[j]+=cookies[i];
            ans=min(ans,rec(i+1,cookies,kids,n,m));
            kids[j]-=cookies[i];
            if(kids[j]==0) break;
        }
        return vis[{kids,i}]=ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
         vector<int>kids(k,0);
         int n=cookies.size();
         return rec(0,cookies,kids,n,k);
    }
};