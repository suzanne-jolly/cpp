class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int maxi=0;
        int l=0;
        int r=0;
        int n=s.size();
        int m=t.size();
        int cur_cost=0;
        while(l<n && r<m){
            cur_cost+=abs(s[r] - t[r]);
            if(cur_cost>maxCost){
                while(cur_cost>maxCost){
                    cur_cost-=abs(s[l]-t[l]);
                    l++;
                }
              
              
            }
            maxi=max(r-l+1,maxi);
            
            r++;
            
            
        }
        return maxi;



        
    }
};