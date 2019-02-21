// a simple solution and Run-time timeout
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int maxDeepth = *(std::max_element(height.begin(),height.end()));
        int minDeepth = *(std::min_element(height.begin(),height.end()));
        vector<int> vi;
        for (size_t i = 0; i < height.size(); ++i)
        {
            vi.push_back(height[i] - minDeepth);
        }
        int ret = 0;
        int newDeepth = maxDeepth - minDeepth;
        for (int i = 0; i < newDeepth; ++i)
        {
            ret += getLowestLayerCap(vi);
            vi = getNew(vi);
        }
        return ret;
    }
private:
    int getLowestLayerCap(vector<int>& height)
    {
        vector<int> ret;
        int count = 0;
        for (size_t i = 0; i < height.size(); ++i)
        {
            if (height[i] >= 1)
            {
                ret.push_back(i);
            }
        }
        for (size_t i = 0; i < ret.size() - 1; ++i)
        {
            count += ret[i + 1] -ret[i] - 1;
        }
        return count;
    }
    
    vector<int> getNew(vector<int>& height)
    {
        vector<int> ret;
        for (size_t i = 0; i < height.size(); ++i)
        {
            if (height[i] >= 1)
            {
                ret.push_back(height[i] - 1);
            }
            else
            {
                ret.push_back(0);
            }
        }
        return ret;
    }
    
};
//using stack
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};
//get left max element and right max element of each element in array
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        int leftMax = 0, rightMax = 0 ,res = 0;
        for (size_t i = 1; i < height.size() - 1; ++i)
        {
            leftMax = 0; rightMax = 0;
            for (size_t j = 0; j < i; ++j)
            {
               leftMax = std::max(leftMax,height[j]);
            }
            for (size_t k = i + 1; k < height.size(); ++k)
            {
               rightMax = std::max(rightMax,height[k]);
            }
            int min = std::min(leftMax,rightMax);
            if (min > height[i])
              res += min - height[i];
        }
        return res;
    }
};
