class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int suf=1;
        int max_prod=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }
            pre*=nums[i];
            suf*=nums[n-i-1];
            max_prod=max(pre,max_prod);
            max_prod=max(suf,max_prod);
        
        }
        return max_prod;
        
    }
};