class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st; // storing the pair of <height, idx> into the stack
        vector<int> res;

        for(int i = n-1; i >= 0; i--) {
            // this one is for the rightest element in the array
            // irrespective of its height, it can always see the ocean view
            if(st.size() == 0) res.push_back(i);

            // we would only consider the buildings having no GREATER ELEMENTS towards RIGHT
            else if(st.size() > 0 and st.top().first < heights[i]) res.push_back(i);

            // and if we are getting any height smaller than the already maintained stack top,
            // we wouldn't even consider that height for insertion into the stack
            // as we are maintaining a STRICTLY GREATER monotonic stack here 
            else if(st.size() > 0 and st.top().first >= heights[i]) continue;
            
            st.push({heights[i], i});
        }

        reverse(res.begin(), res.end());

        return res;
    }
};