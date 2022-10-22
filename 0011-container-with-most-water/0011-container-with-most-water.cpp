class Solution {
public:
    // area=len*height
    // take initail max len and then compress it using two pointers for max area
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
             ans=max(ans,min(heights[i],heights[j])*(j-i));
             if(heights[i]<heights[j]) i++;
             else if(heights[i]>heights[j]) j--;
             else if(heights[i]==heights[j]){
                 i++;
                 j--;
             }
        }
        return ans;
    }
};