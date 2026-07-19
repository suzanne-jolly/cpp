class Solution {
public:
    bool isValid(string& word) {
        int n = word.size();
        int hyphenCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (isdigit(word[i])) return false; // Rule: No digits
            
            if (word[i] == '-') {
                hyphenCount++;
                // Rule: More than one hyphen or hyphen at start/end
                if (hyphenCount > 1 || i == 0 || i == n - 1) return false;
                // Rule: Hyphen must be surrounded by letters
                if (!islower(word[i - 1]) || !islower(word[i + 1])) return false;
            }
            
            if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                // Rule: Punctuation must be at the end
                if (i != n - 1) return false;
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        int count = 0;
        string word;
        stringstream ss(sentence);
        
        // Use stringstream to easily split by spaces
        while (ss >> word) {
            if (isValid(word)) {
                count++;
            }
        }
        return count;
    }
};