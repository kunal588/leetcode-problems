class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<1) ans=max(ans,1-sum);
        }
        return ans;
    }
};