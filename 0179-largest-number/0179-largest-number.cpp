class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto it: nums){
            arr.push_back(to_string(it));
        }
        sort(arr.begin(), arr.end(),
        [] (const string& a, const string& b){

            return a+b>b+a;//custom comparator for strings

        });
        if(arr[0]=="0"){
            return "0";

        } 
        string ans;
        for(auto it: arr){
            ans+=it;

        }
        return ans;
        
    }
};