// 2349. Design a Number Container System
// https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

class NumberContainers {
    unordered_map<int, int> mp1;                //index to number
    unordered_map<int, set<int>> mp2;           // no. to set of indexes

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (mp1.find(index) == mp1.end())
            mp1[index] = number;
        else {
            int num = mp1[index];
            mp2[num].erase(index);
            if (mp2[num].empty()) {
                mp2.erase(num);
            }
        }
        mp2[number].insert(index);
        mp1[index] = number;
    }

    int find(int number) {
        if (mp2.find(number) != mp2.end() && !mp2[number].empty())
            return *mp2[number].begin();
        else
            return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
