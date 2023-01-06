#include<bits/stdc++.h>
using namespace std;
class Multimatch{
    public:
    string exp;
    Multimatch(string s){
        exp=s;
    }
    bool isMatch(){
        stack<char> stk;
        char check;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
               stk.push(exp[i]);
            }
            else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
                if(stk.empty()){
                    return 0;
                }
                switch(exp[i]){
                    case ')':{
                        if(stk.top()=='('){
                            stk.pop();
                        }
                        else{
                            return false;
                        }
                        break;
                    }
                    case '}':{
                        if(stk.top()=='{'){
                            stk.pop();
                        }
                        else{
                            return false;
                        }
                        break;
                    }
                    case ']':{
                        if(stk.top()=='['){
                            stk.pop();
                        }
                        else{
                            return false;
                        }
                        break;
                    }
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Multimatch m("9-{{4+(7-8)-[5-67]}}");
    cout<<m.isMatch();
}