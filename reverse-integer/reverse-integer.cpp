vector<int> getDigits(int n)
{
    vector<int> v;
    while(n>0)
    {
        v.push_back(n%10);
        n/=10;
    }
    return v;
}

class Solution {
public:
    int reverse(int x) {
        int final = 0;
        if (x == 0)
            return 0;
        if (x > 0)
        {
            int multiplier = 1; 
            vector<int> d = getDigits(x);
            for (int i = d.size()-1;i>=0;i--)
            {
                if (d[i] <= INT_MAX/multiplier && final <= INT_MAX - multiplier*d[i])
                    final+=multiplier*d[i];
                else
                    return 0;
                if (multiplier <= INT_MAX/10)
                    multiplier*=10;
                else if (i!=0)
                    return 0;
            }
        }
        else
        {
            if (x == INT_MIN)
                return 0;
            return -1*reverse(-1*x);
        }
        return final;
    }
};