#include<bits/stdc++.h>
using namespace std;
class Match{
    public:
    string exp;
    Match(string s){
       exp=s;
    }
    bool isMatch(){
        stack<char> stk;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='('){
                stk.push(exp[i]);
            }
            else if(exp[i]==')'){
                if(stk.empty()){
                    return false;
                }
                else{
                    stk.pop();
                }
                
            }
        }
        return true;
    }
};
int main()
{
    Match m("7-8(5-6)-(5-7)4-898)86)");
    cout<<m.isMatch();
    return 0;
}