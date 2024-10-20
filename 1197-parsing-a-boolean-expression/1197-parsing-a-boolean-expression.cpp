class Solution {
public:
    char perform(char op1, char op2, char opr){
        bool oprand1 = op1 == 't'?true:false;
        bool oprand2 = op2 == 't'?true:false;
        if(opr == '&')
        return (oprand1 & oprand2)?'t':'f';
        else
        return (oprand1 & oprand2)?'t':'f'; 
    }

    bool parseBoolExpr(string expression) {
        stack<char> st;
        string str = expression;
        int i = expression.length() - 1;
        st.push(expression[i--]);
        while(i >= 0){
            if(str[i] == ',')
            i--;
            else if(str[i] == ')' || str[i] == 't' || str[i] == 'f')
            st.push(str[i--]);
            else{
                i--;
                char op = str[i--];
                char temp = st.top();
                st.pop();
                if(op == '!')
                temp = (temp == 't')?'f':'t';
                else if(op == '&'){
                    while(st.top()!=')'){
                        if(st.top() == 'f'){
                            temp = 'f';
                        }
                        st.pop();
                    }
                }
                else{
                    while(st.top()!=')'){
                        if(st.top() == 't'){
                            temp = 't';
                        }
                        st.pop();
                    }
                }
                st.pop();
                st.push(temp);
            }
        }
        return st.top() == 't';
    }
};