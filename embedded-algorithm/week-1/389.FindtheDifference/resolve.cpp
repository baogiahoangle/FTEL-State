class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[256] = {0};
        for(int i = 0; i < t.size(); i++)
        {
            count[s[i]] -= 1;
            count[t[i]] += 1;
        }   
        for(int i = 0; i < 256; i++)
        {
            if(count[i] == 1)
                return char(i);
        }
        return char(0);
    }
};