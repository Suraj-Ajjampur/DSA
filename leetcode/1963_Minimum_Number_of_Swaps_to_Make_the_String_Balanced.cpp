class Solution {
public:
    int minSwaps(string s) {
        // Initialize a stack to keep track of unmatched opening 
        // brackets [ and an integer unbalanced to count unbalanced closing brackets ].

        stack<char> stack;
        int unbalanced = 0;
        for (int i = 0; i < s.size(); i++){
            char ch = s[i];
            //If an opening bracket is encountered, push it in the stack
            if (ch == '[')
                stack.push(ch);
            else {
                //If the stack is not empty, pop it
                if (!stack.empty()) stack.pop();
                //Other wise increate the count of unbalanced brackets
                else
                    unbalanced++;

            }
        }
        return (unbalanced + 1)/2;
    }
};
