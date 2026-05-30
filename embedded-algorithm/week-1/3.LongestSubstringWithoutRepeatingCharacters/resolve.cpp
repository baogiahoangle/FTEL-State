class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int quantity = 1, max = 1;
        int count[256] = {0};
        int check_point = 0;
        count[s[0]] = 1;
        for(int i = 1; i < s.size(); i++)
        {
            while(count[s[i]] >= 1)
            {
                count[s[check_point++]] = 0;
                quantity--;
            }
            quantity++;
            count[s[i]] += 1;
            if(quantity > max)
                max = quantity;
        }
        return max;
    }
};