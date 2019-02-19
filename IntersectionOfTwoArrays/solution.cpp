// First 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return vector<int>();
        }
        set<int>  snums1;
        set<int>  snums2;

        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
        {
            snums1.insert(*it);
        }
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
        {
            snums2.insert(*it);
        }
        int min1 = *snums1.begin();
        int max1 = *snums1.rbegin();
        int min2 = *snums2.begin();
        int max2 = *snums2.rbegin();
        
        if (min1 > max2 || min2 > max1)
        {
            return  vector<int>();
        }
        vector<int>  vret;

            for (set<int>::iterator it = snums2.begin(); it != snums2.end(); ++it)
            {
                auto ret = snums1.find(*it);
                if (ret != snums1.end())
                {
                    vret.push_back(*it);
                }
            }

        return vret;
        
    }
};
// second optimize
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return vector<int>();
        }
        set<int>  snums1;
        set<int>  snums2;

        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
        {
            snums1.insert(*it);
        }
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
        {
            snums2.insert(*it);
        }
        int min1 = *snums1.begin();
        int max1 = *snums1.rbegin();
        int min2 = *snums2.begin();
        int max2 = *snums2.rbegin();
        
        if (min1 > max2 || min2 > max1)
        {
            return  vector<int>();
        }
        vector<int>  vret;
        vret.reserve(snums1.size());

            for (set<int>::iterator it = snums2.begin(); it != snums2.end(); ++it)
            {
                auto ret = snums1.find(*it);
                if (ret != snums1.end())
                {
                    vret.push_back(*it);
                }
            }

        return vret;
        
    }
};
// third optimize
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return vector<int>();
        }
        set<int>  snums1;
        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
        {
            snums1.insert(*it);
        }
        set<int>  vset;
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
        {
            auto ret = snums1.find(*it);
            if (ret != snums1.end())
            {
                vset.insert(*it);
            }
        }

        return vector<int>(vset.begin(),vset.end());
        
    }
};
// fourth optimize
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return vector<int>();
        }
        set<int>  snums1(nums1.begin(),nums1.end());
        set<int>  vset;
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
        {
            int ret = snums1.count(*it);
            if (ret)
            {
                vset.insert(*it);
            }
        }

        return vector<int>(vset.begin(),vset.end());
        
    }
};
