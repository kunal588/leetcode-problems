class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
             int len=ans.size();
             if(nums[i]>ans[len-1]) ans.push_back(nums[i]);
             else{
                  auto itr=lower_bound(ans.begin(),ans.end(),nums[i]);
                  *itr=nums[i];
             }
        }
        return ans.size();
    }
};