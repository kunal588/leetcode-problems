class Solution {
public:
    int LPS(string s1){
        int n=s1.length();
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                  if(s1[i-1]==s2[j-1]){
                      dp[i][j]=1+dp[i-1][j-1];
                  }
                  else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int maxProduct(string s) {
        int n=s.length();
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++){
            string s1,s2;
            for(int i=0;i<n;i++){
                if((mask&(1<<i))==0){
                    s1+=s[i];
                }
                else s2+=s[i];
            }
            ans=max(ans,LPS(s1)*LPS(s2));
        }
        return ans;
    }
};