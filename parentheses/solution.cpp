class Solution {
public:
    bool isValid(string s) {
        std::stack<char> sCh;
        for (size_t i = 0; i < s.size(); ++i)
        {
            const char c = s.at(i);
            if (c == '(' || c == '{' || c == '[')
            {
                sCh.push(c);
            }
            else if (sCh.empty())
            {
                return false;
            }
            else
            {
                const char c1 = sCh.top();
                if ((c == ')' && c1 == '(') || 
                    (c == ']' && c1 == '[') || 
                    (c == '}' && c1 == '{'))
                {
                    sCh.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (sCh.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
