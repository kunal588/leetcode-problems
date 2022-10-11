class Solution {
public:
    //not dp
    //greedy approach
    int minTaps(int n, vector<int>& ranges) {
        vector<int>v(n+1,0);
        for(int i=0;i<=n;i++){
            int l=max(i-ranges[i],0);
            int r=min(i+ranges[i],n);
            v[l]=max(v[l],r-l);
        }
        int max_reachable=0;
        int curr_reach=0;
        int jumps=0;
        for(int i=0;i<n;i++){
            max_reachable=max(max_reachable,i+v[i]);
            if(i==curr_reach){
                jumps++;
                curr_reach=max_reachable;
            }   
        }
        if(curr_reach!=n) return -1;
        return jumps;

        

        
    }
};