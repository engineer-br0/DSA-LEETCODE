class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r){
        int left = l;
        int right = mid+1;
        int final = 0;
        vector<int> v(r - l +1, -1);
        while(final <= r - l ){
            if(left > mid) v[final++] = nums[right++];
            else if(right > r) v[final++] = nums[left++];
            else v[final++] = (nums[left] < nums[right])? nums[left++] : nums[right++];
        }
        for(int i : v) nums[l++] = i;
    }
    void mergesort(vector<int>& nums, int l, int r){
        if(l < r){
        int mid = l + ((r-l)>>1);
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        merge(nums, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};