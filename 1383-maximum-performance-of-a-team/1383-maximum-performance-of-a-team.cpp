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
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pii>v;
        ll mx=0;
        fitr(i,0,n){
            v.pb(pii(e[i],s[i]));
        }
        sort(rangeitr(v),greater<pii>());
        priority_queue<int>pq;
        ll sum=0;
        for(auto p:v){
            int effi=p.first;
            int speed=p.second;
            sum+=speed;
            pq.push(-speed);
            if(pq.size()>k){
                sum+=pq.top();
                pq.pop();
            }
            mx=max(mx,sum*effi);
        }
        return mx%M;
    }
};