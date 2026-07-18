class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        int cnt=0;
        
        
        
        unordered_map<int,int>m;
        m[0]=1;
        int total=0;
      
        for(int i=0; i<n; i++){
            total+=nums[i];
            if(m.find(total-k)!=m.end()){
                cnt+=m[total-k];
            }
            m[total]++;

        }
        return cnt;
        
    }
};