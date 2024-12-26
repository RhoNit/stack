// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/0

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> res;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(st.size() == 0) res.push_back(-1);
            else if(st.size() > 0 and st.top() < a[i]) {
                res.push_back(st.top());
            }
            else if(st.size() > 0 and st.top() >= a[i]) {
                while(st.size() > 0 and st.top() >= a[i]) {
                    st.pop();
                }
                if(st.size() == 0) res.push_back(-1);
                else res.push_back(st.top());
            }
            
            st.push(a[i]);
        }
        
        return res;
    }
};