class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // If characters match, move inward
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // If there's a mismatch, we have two choices:
                // 1. Delete the character at 'left'
                // 2. Delete the character at 'right'
                // If either resulting substring is a palindrome, return true.
                return checkPalindrome(s, left + 1, right) || 
                       checkPalindrome(s, left, right - 1);
            }
        }
        
        return true;
    }
    
private:
    // Helper function to check if a specific substring is a palindrome
    bool checkPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};