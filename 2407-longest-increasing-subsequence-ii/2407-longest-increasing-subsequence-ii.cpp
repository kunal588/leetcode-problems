#define N 1000000
class Solution {
public:
    int seg[N];
    int query(int node,int n_l,int n_h,int q_l,int q_h){
        if(q_l<=n_l && n_h<=q_h) return seg[node];
        if(q_h<n_l || n_h<q_l) return 0;
        int mid=(n_l+n_h)/2;
        int v1=query(2*node,n_l,mid,q_l,q_h);
        int v2=query(2*node+1,mid+1,n_h,q_l,q_h);
        return max(v1,v2);
    }
    void update(int node,int n_l,int n_h,int q,int val){
        if(q<=n_l && n_h<=q){
            seg[node]=val;
            return;
        }
        if(q<n_l || n_h<q) return;
        int mid=(n_l+n_h)/2;
        update(2*node,n_l,mid,q,val);
        update(2*node+1,mid+1,n_h,q,val);
        seg[node]=max(seg[2*node],seg[2*node+1]);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        int m=100000;
        if(__builtin_popcount(m)!=1){
            m=pow(2,(int)log2(m)+1);
        }
        int res=0;
        for(int i=0;i<n;i++){
            int left=nums[i]-k;
            int right=nums[i]-1;
            int mx=query(1,1,m,left,right);
            res=max(res,1+mx);
            update(1,1,m,nums[i],1+mx);
        }
        return res;
    }
};