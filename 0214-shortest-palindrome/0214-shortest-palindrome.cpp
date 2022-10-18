class Solution {
public:
    vector<int>lps;
    void make_lps(string s,int n){
        int i=0,j=1;
        lps[0]=0;
        while(j<n){
            if(s[i]==s[j]){
                lps[j]=i+1;
                i++;
                j++;
            }
            else if(i==0){
                lps[j]=0;
                j++;
            }
            else{
                i=lps[i-1];
            }
        }
    }
    string kmp(string t,string p,int n,int m){
        int i=0,j=0;
        for(;i<n;i++){
            while(j!=0 && (j==m || t[i]!=p[j])){
                  j=lps[j-1];
            }
            if(t[i]==p[j]){
                j++;
            }
        }
        string extra=p.substr(j);
        reverse(extra.begin(),extra.end());
        return extra+p;
    }
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=t.length();
        if(n==0) return "";
        lps=vector<int>(n);
        make_lps(s,n);
        return kmp(t,s,n,n);
    }
};