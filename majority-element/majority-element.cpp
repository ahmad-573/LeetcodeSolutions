class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int curr_count = 1;
        int curr_number = nums[0];
        for (int i = 1;i<n;i++)
        {
            if (curr_count > n/2)
                return curr_number;
            if (nums[i] != curr_number)
            {
                curr_number = nums[i];
                curr_count = 1;
            }
            else
                curr_count++;
        }
        return curr_number;
    }
};