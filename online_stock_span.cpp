class StockSpanner {
private:
    stack<pair<int, int>> st; // we will store a pair of <price, span> into the stack
public:
    StockSpanner() {}
    
    int next(int price) {
        int curr_span = 1; // default span is 1

        // till we find the equal or lesser price in stack top,
        // we will increase the `curr_span` 1 by 1
        // and will pop the stack top one by one
        while(st.size() > 0 and st.top().first <= price) {
            curr_span += st.top().second;
            st.pop();
        }
        st.push({price, curr_span});

        return curr_span;
    }
};