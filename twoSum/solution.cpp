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
// a new method 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
      size_t size = nums.size();
      unordered_map<int,int>  tmp_map;
      for (size_t i = 0; i < size; i++)
      {
          if (tmp_map.count(target - nums[i]))
          {
              return vector<int> {tmp_map[target - nums[i]],i};
          }
          tmp_map[nums[i]] = i;
      }
      return vector<int>();
    }
};
