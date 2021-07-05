class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> final;
        int n = nums.size();
        int half = 0;
        if (target%2 == 0)
        {
            for (int i = 0;i<n;i++)
            {
                if (nums[i] == target/2)
                    half++;
            }
            if (half == 1)
            {
                for (int i = 0;i<n;i++)
                {
                    if (nums[i] == target/2)
                    {
                        nums[i] = 2*target+1;
                    }
                }
            }
            else if (half > 1)
            {
                for (int i = 0;i<n;i++)
                {
                    if (nums[i] == target/2)
                    {
                        final.push_back(i);
                    }
                    if (final.size()==2)
                        return final;
                }
            }
        }
        vector<int> nums_sorted;
        vector<int> other;
        for (int i = 0;i<n;i++)
        {
            nums_sorted.push_back(nums[i]);
            other.push_back(target-nums[i]);
        }
        //sort(nums_sorted.begin(),nums_sorted.end());
        //sort(other.begin(),other.end());
        int n1;
        int n2;
        unordered_map<int,int> mymap;
        int count =0;
        for (int i = 0;i<n;i++)
        {
            if (nums_sorted[i] == other[i] && count == 0){
                count++;
                continue;
            }
            mymap[nums_sorted[i]]++;
            mymap[other[i]]++;
        }
        for (auto x : mymap)
        {
            if (x.second >= 2)
            {
                n1 = x.first;
                n2 = target-n1;
            }
        }
        for (int i = 0;i<n;i++)
        {
            if (nums[i] == n1)
                final.push_back(i);
            if (nums[i] == n2)
                final.push_back(i);
            if (final.size() == 2)
                break;
        }
 
        return final;
    }
};