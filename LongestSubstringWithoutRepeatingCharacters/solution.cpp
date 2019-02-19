class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<int> si;
        int ans = 0, i = 0 , j = 0;
        while( i < s.size() && j < s.size())
        {
            auto ret = si.find(s.at(j));
            if (ret == si.end())
            {
                si.insert(s.at(j++));
                ans = std::max(ans,j - i);
            }
            else
            {
                auto it = si.find(s.at(i++));
                si.erase(it);
            }
        }
        return ans;
    }
};
