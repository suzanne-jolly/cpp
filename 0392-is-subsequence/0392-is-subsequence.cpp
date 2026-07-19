class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        int r=0;
        int n=s.size();
        int c=0;
        int m=t.size();
        while(l!=n && r<m && l<n){
            if(s[l]==t[r]){
                l++;
                r++;
                c++;
            }else{
                r++;
            }
        }
        if(c==n){
            return true;
        }
        return false;
        
    }
};