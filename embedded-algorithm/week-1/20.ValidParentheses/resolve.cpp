class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0)
            return false;
        char copy[s.size()];
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            switch(s[i])
            {
                case '{':
                case '(':
                case '[':
                    copy[count++] = s[i];
                    break;
                case '}':
                    if(count == 0 || copy[count - 1] != '{')
                        return false;
                    count--;
                    break;
                case ']':
                    if(count == 0 || copy[count - 1] != '[')
                        return false;
                    count--;
                    break;
                case ')':
                    if(count == 0 || copy[count - 1] != '(')
                        return false;
                    count--;
                    break;
            }
            
        }
        if(count!=0)
            return false;
        return true;
    }
};