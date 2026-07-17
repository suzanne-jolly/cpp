class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=2;i<nums.size();){
            if(nums[i]==nums[i-2]){
                nums.erase(nums.begin()+i,nums.begin()+i+1);
            }else{
                i++;
            }
        }
        return nums.size();
        
    }
};