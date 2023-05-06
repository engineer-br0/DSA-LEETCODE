class Solution {
public:
    int findDuplicate(vector<int>& nums) {  // [1,3,4,2,2]
        int n = nums.size();  // 5
        for(int i =0; i<n; i++){
            if(i != nums[i] - 1){ // pehle se hi sahi position pr na ho
               if(nums[i] == nums[nums[i] - 1]) return nums[i];  // duplicate found
               else{
                   swap(nums[i], nums[nums[i] - 1]);  // move to sahi position
                   i--;  // fir se chek krro coz naya ele aa gya
               }
            }
        }
        return -1;  // never met condition, yet we have to return a int
    }
};