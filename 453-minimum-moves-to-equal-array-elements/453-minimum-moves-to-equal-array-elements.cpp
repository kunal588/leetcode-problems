class Solution {
public:
    // reverse the probem
    // increasing n-1 elements by 1 == decreasing 1 element by 1 
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves=0;
        for(auto i:nums){
            moves+=i-nums[0];
        }
        return moves;
    }
};