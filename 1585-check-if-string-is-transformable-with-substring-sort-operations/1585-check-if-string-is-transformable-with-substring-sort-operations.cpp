#define N 200002
#define M 1000000007
#define fitr(i,a,b) for(auto i=a;i<b;i++)
#define ritr(i,a,b) for(auto i=b;i>=a;i--)
#define print(a) cout<<a<<endl
#define pb(a) push_back(a)
#define rangeitr(a) a.begin(),a.end()
#define pii pair<int,int>
#define ll long long int 
#define ld long double

class Solution {
public:
    //amazing implementation
    bool isTransformable(string s, string t) {
        int n=s.length();
        vector<vector<int>>ids(10);
        fitr(i,0,n) ids[s[i]-'0'].pb(i);
        vector<int>pos(10,0);
        for(char ch:t){
            int curr=ch-'0';
            if(pos[curr]>=ids[curr].size()) return false;
            fitr(i,0,curr){
                if(pos[i]<ids[i].size() && ids[i][pos[i]]<ids[curr][pos[curr]] ) return false;
            }
            pos[curr]++;
        }
        return true;
    }
};