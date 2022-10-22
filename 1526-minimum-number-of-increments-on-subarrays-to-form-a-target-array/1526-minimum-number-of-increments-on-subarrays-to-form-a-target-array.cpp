class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int active_subarray=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(active_subarray<=target[i]){
                ans+=target[i]-active_subarray;
                active_subarray=target[i];
            }
            else{
                 active_subarray=target[i];
            }
        }
        return ans;
    }
};