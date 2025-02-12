// 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;
        for (int i : nums) {
            int sum = 0, n = i;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            mp[sum].push(i);
        }

        int ans = -1;
        for (auto& i : mp) {
            if (i.second.size() > 1) {
                int sum = i.second.top();
                i.second.pop();
                sum += i.second.top();
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
