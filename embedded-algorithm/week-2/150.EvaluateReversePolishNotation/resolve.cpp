class Solution {
public:
    bool if_operand(char oper)
    {
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
            return true;
        return false;
    }
    int calculation_operand(int c1, int c2, char operand)
    {
        switch(operand)
        {
            case '+':
                return c1 + c2;
            case '-':
                return c1 - c2;
            case '*':
                return c1 * c2;
            case '/':
                return c1 / c2;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> results;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(!if_operand(tokens[i][0]) || tokens[i].size() > 1)
                results.push(stoi(tokens[i]));
            else
            {
                int c2 = results.top();
                results.pop();
                int c1 = results.top();
                results.pop();
                results.push(calculation_operand(c1, c2, tokens[i][0]));
            }
        }
        return results.top();
    }
};