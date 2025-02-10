
// 3174. Clear Digits
// https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10










class Solution {
public:
    string clearDigits(string s) {
        string res = "";
        for (char c : s) {
            if (isdigit(c)) {
                if (!res.empty()) {
                    res.pop_back(); 
                }
            } else {
                res.push_back(c); 
            }
        }
        return res;
    }
};
