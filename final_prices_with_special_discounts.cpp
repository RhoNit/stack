class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result;
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            if(st.size() == 0) result.push_back(-1);
            else if(st.size() > 0 and st.top() <= prices[i]) result.push_back(st.top());
            else if(st.size() > 0 and st.top() > prices[i]) {
                while(st.size() > 0 and st.top() > prices[i]) st.pop();
                if(st.size() == 0) result.push_back(-1);
                else result.push_back(st.top());
            }
            st.push(prices[i]);
        }

        reverse(result.begin(), result.end());

        int idx = 0;
        for(auto elem: prices) {
            if(result[idx] == -1) result[idx] = elem;
            else result[idx] = elem-result[idx];
            
            idx++;
        }

        return result;
    }
};