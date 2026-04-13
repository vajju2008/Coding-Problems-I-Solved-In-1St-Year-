class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int left = 0;
        int right = 0;

        for (int i = 0; i < k; i++) {
            left += nums[i];
            right += nums[size - k + i];
        }

        if (left > right)
            return left - right;
        else
            return right - left;
    }
};


