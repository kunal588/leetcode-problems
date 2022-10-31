class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
         map<int,int>m;
         m[-1]=0;
         int x=0;
         int n=s.length();
         for(int i=0;i<n;i++){
             x^=(1<<(s[i]-'a'));
             m[i]=x;
         }
        vector<bool>ans;
         for(auto v:queries){
             int l=v[0];
             int h=v[1];
             int can=v[2];
             int y=m[h]^m[l-1];
             int cnt=__builtin_popcount(y);
             if(cnt/2<=can) ans.push_back(1);
             else ans.push_back(0);
         }
        return ans;
    }
};