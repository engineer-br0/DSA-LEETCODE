class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i : nums){
            if(++mp[i] == 2) return true;
        }
        return false;
    }
};