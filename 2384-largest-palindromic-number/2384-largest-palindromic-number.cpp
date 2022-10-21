class Solution {
public:
    string largestPalindromic(string num) {
        int n=num.size();
        vector<int>m(10,0);
        for(int i=0;i<n;i++){
            m[num[i]-'0']++;
        }
        string ans;
        string rev;
        int mx=-1;
        for(int i=9;i>=0;i--){
            while(m[i]-2>=0 && !((int)ans.size()==0 && i==0)){
                ans+=(i+'0');
                rev+=(i+'0');
                m[i]-=2;
            }
            if(m[i]>0) mx=max(mx,i);
        }
        reverse(rev.begin(),rev.end());
        if(mx==-1) return ans+rev;
        else return ans+to_string(mx)+rev;
        
    }
};