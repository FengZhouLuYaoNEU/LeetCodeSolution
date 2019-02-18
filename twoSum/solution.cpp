class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> ret;
      size_t size = nums.size();
      for (size_t i = 0; i < size; i++)
      {
          for (size_t j = i + 1; j < size; j++)
          {
              if ((nums[i] + nums[j]) == target)
              {
                  ret.push_back(i);
                  ret.push_back(j);
                  break;
              }
          }
      }
      return ret;
    }
};
