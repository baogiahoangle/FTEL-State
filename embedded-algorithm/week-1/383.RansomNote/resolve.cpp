class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        int count[256] = {0};
        int data_valid = 0;
        for(int i = 0; i < magazine.size(); i++)
        {
            count[magazine[i]]--;
            if(i < ransomNote.size())
                count[ransomNote[i]]++;
        }
        for(int i = 0; i < 256; i++)
        {
            if(count[i] > 0)
                return false;
        }
        return true; 
    }
};