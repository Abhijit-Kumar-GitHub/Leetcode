// 3160. Find the Number of Distinct Colors Among the Balls

// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // int n = queries.size();
        // unordered_map<int, int>colorMap;        //stores which color, and how many of that. updates too
        // vector<int> ans(n);                     //to give out the state of colr throughout
        // vector<int> balls(limit+1,0);             //index as which ball, value as which color. 0 is as if no color


        // for(int i =0; i<n; i++){
        //     int ball = queries[i][0];
        //     int color = queries[i][1];

        //     if(balls[ball] != 0 ){
        //         int prevC = balls[ball];
        //         colorMap[prevC]--;

        //         if(colorMap[prevC] == 0){
        //             colorMap.erase(prevC);
        //         }
        //     }


        //     // this will actual flow start
        //     balls[ball] = color;
        //     colorMap[color]++;
        //     ans[i] = colorMap.size();

        // }
        // return ans;                                                          // give memory limit exceeded. 

        vector<int>ans(queries.size());
        unordered_map<int, int>cMap;        // col to count
        unordered_map<int, int>bMap;        // ball to col

        for(int i = 0; i < queries.size();i++){
            int b = queries[i][0];
            int c = queries[i][1];

            if(bMap.find(b) != bMap.end()){     // true if it finds occurence of ball b in bMap and the appropriately -- the color or even removeing frm cMap. then we update the new vals.
                int prevC = bMap[b];
                cMap[prevC]--;

                if(cMap[prevC] == 0){
                    cMap.erase(prevC);
                }
            }

            bMap[b] = c;
            cMap[c]++;

            ans[i] = cMap.size();

        }
        return ans;






    }
};
