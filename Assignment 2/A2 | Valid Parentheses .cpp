//Leetcode problem
//Valid Parentheses
//Problem link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> helloji;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                helloji.push(s[i]);

            }else if(s[i]==')'){
                if(helloji.empty()){return false;}
                if(helloji.top()!='('){
                    return false;

                }helloji.pop();
            }else if(s[i]=='}'){
                if(helloji.empty()){return false;}
                if(helloji.top()!='{'){
                    return false;
                }helloji.pop();
            }else if(s[i]==']'){
                if(helloji.empty()){return false;}
                if(helloji.top()!='['){
                    return false;
                }helloji.pop();
            }
        }if(helloji.empty()){return true;}
        else {return false;}
    }
};