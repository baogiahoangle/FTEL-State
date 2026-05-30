class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max = 0;
        for(int i = 0; i < k; i++)
        {
            max += nums[i];
        }
        double ave = max;
        for(int i = 0; i < nums.size() - k; i++)
        {
            max = (max - nums[i] + nums[i + k]);
            if(ave < max)
                ave = max;
        }
        return ave / k;
    }
};