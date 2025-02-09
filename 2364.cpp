// 2364. Count Number of Bad Pairs
// https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09



class Solution {
public:
        //here we sub the index from the value to reveal underlying pattern. Also j-i = nums[j] - nums[i] are good pairs which is easier to count. find them and sub them from total pair possible.
    long long countBadPairs(vector<int>& nums) {
        // long long bad = 0;
        // unordered_map<int, int>diffMap;        


        // for(int i =0; i< nums.size(); i++){
        //     int diff = i - nums[i];

        //     int good = diffMap[diff];

        //     bad += i-good;

        //     diffMap[diff] = good+1;
        // }
        // return bad;


        //---------approach 2

        long long int b=nums.size();
        long long g = 0;
        long long k = 0;

        for(int i=0; i<b; i++){
            nums[i] = i-nums[i];
        }

        sort(nums.begin(), nums.end());

        for(int i=0; i<b-1; i++){
            if(nums[i] == nums[i+1]){
                k++;
                }
            else{
                g = g+(k*(k+1))/2;
                k=0;
                }
        }
        return (b*(b-1))/2 - g - (k*(k+1))/2;
    }
};
