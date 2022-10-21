#define M 1000000007
class Solution {
public:
    int numberOfCombinations(string num) {
        int n=num.size();
        int lcp[n+1][n+1];
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++){
           for(int j=0;j<n+1;j++){
               dp[i][j]=0;
               lcp[i][j]=0;
           }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(num[i]==num[j]) lcp[i][j]=1+lcp[i+1][j+1];
            }
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(num[i-1]=='0'){
                     dp[i][j]+=dp[i-1][j];
                     continue;
                }
                int len=j-i+1;
                dp[i][j]=(M+0ll+dp[i][j]+dp[i-1][i-1]-((i-len>0)?dp[i-len][i-1]:0))%M;
                if(i-1-len>=0){
                    bool ok=0;
                    if(len<=lcp[i-1-len][i-1]) ok=1;
                    else if(num[i-1-len+lcp[i-1-len][i-1]]<num[i-1+lcp[i-1-len][i-1]]) ok=1;
                    if(ok) dp[i][j]=(M+0ll+dp[i][j]+dp[i-len][i-1]-dp[i-len-1][i-1])%M;
                }
                dp[i][j]=(0ll+dp[i][j]+dp[i-1][j])%M;
            }
        }
        return dp[n][n];
    }
};