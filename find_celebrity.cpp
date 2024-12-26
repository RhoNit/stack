/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // we would store the graph nodes i.e. 0 to (n-1) into a stack
        stack<int> st;
        for(int i = 0; i < n; i++) st.push(i);

        // now we will process the elements one by one from the stack top till `n` number of times
        int counter = 0;
        while(counter != n-1) {
            int first_person = st.top();
            st.pop();

            int second_person = st.top();
            st.pop();

            // check - Whether A knows B
            if(knows(first_person, second_person)) st.push(second_person); // B is known to A that means B is a potential celebrity
            else st.push(first_person);

            counter++;
        }

        // there could be scenarios where st.top() element is not known by every elements
        // for example, 2 is known by 1 -> st.top() = 2
        // now 2 is not known by 0 hence 2 can't be the celebrity but 0 has the potential to be a celebrity -> st.top() = 0
        // we also can't confirm whether 0 is the celebrity
        // for that, we need to confirm other cases i.e. whether 1 and 2 know 0 or not
        // so for now we are 0 as potential_celeb
        int potential_celeb = st.top();
        for(int i = 0; i < n; i++) {
            // ignoring the diagonal cells i.e. graphs[0][0]
            if(i != potential_celeb) {
                // case 1: 1 and 2 don't know 0
                // case 2: 0 knows 1 and(or) 2 
                if(knows(i, potential_celeb) == 0 or knows(potential_celeb, i) == 1) {
                    return -1;
                }
            }
        }

        return potential_celeb;
    }
};