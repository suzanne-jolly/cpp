class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n=s.size();
        if(n==0){
            return 0;
        }
        unordered_set<char>m;
        int maxi=1;
        m.insert(s[0]);
        for(int r=1;r<n;r++){
            if(m.find(s[r])!=m.end()){
                while(m.find(s[r])!=m.end()){
                    m.erase(s[l]);
                    l++;
                    
                    
                }
                maxi=max(r-l+1,maxi);
                
                
            }else{
                
                maxi=max(r-l+1,maxi);

            }
            
            m.insert(s[r]);

        }
        return maxi;
        
    }
};