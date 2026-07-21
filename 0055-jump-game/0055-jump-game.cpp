class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_idx=0;
        for(int i=0; i<n;i++){
            if(i>max_idx){
                return false;
            }
            max_idx=max(max_idx,i+nums[i]);//rn wherever u are u can only reach i+nums[i] from here..so just keep looking at max last reachable index
            
        }
        return true;
        
    }
};