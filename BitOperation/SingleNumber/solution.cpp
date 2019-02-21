class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            a ^= *it;
        }
        return a;
    }
};
// easy method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(),0,bit_xor<int>());
    }
};
