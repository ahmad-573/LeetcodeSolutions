class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int arr[nums1.size()][nums2.size()];
        for (int i = 0;i<nums1.size();i++)
        {
            for (int j = 0;j<nums2.size();j++)
            {
                arr[i][j] = nums1[i] - nums2[j];
            }
        }
        int m = -1;
        for (int i = 1;i <= nums1.size()+nums2.size()-1;i++)
        {
            int j,r;
            if (i <= nums1.size())
            {
                j = 0;
                r = nums1.size()-i;
            }
            else
            {
                r = 0;
                j = i - nums1.size();
            }
            int cons = 0;
            while(r < nums1.size() && r >= 0 && j < nums2.size() && j>=0)
            {
                if (arr[r][j] == 0)
                {
                    cons++;
                }
                else{
                    cons = 0;
                }
                m = max(m,cons);
                
                r++;
                j++;
            }
        }
        return m;
    }
};