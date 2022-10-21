#define ll long long int 
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int>v;
        for(int i=0;i<nums.size();i++) if(nums[i]==1) v.push_back(i);
        vector<ll>pref;
        pref.push_back(0);
        int n=v.size();
        for(int i=0;i<n;i++){
            pref.push_back(pref.back()+v[i]);
        }
        pref.push_back(pref.back());
        ll ans=INT_MAX;
        for(int i=k-1;i<n;i++){
               int mid=i-k+1+k/2;
               ll left_sum=pref[mid]-pref[i-k+1];
               ll right_sum=pref[i+1]-pref[mid+1];
               ll temp=-left_sum+right_sum-(k/2)*((k+1)/2);
               if(k%2==0) temp+=v[mid];
               ans=min(ans,temp);
        }
        return ans;
    }
};