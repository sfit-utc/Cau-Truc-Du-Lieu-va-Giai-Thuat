#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;  
    stack<char> opr;
    vector<char> BLExp;
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            BLExp.push_back(c);
        }
        else
        {
            if (c == ')')
            {
                while (!opr.empty())
                {
                    if (opr.top() != '(')
                    {
                        BLExp.push_back(opr.top());
                        opr.pop();
                    }
                    else break;
                }
                opr.pop();
            }
            else
            {
                if (c == '+' || c == '-')
                {
                    while (!opr.empty())
                    {
                        if (opr.top() != '(')
                        {
                            BLExp.push_back(opr.top());
                            opr.pop();
                        }
                        else break;
                    }
                }
                else if (c == '*' || c == '/')
                {
                    while (!opr.empty())
                    {
                        if (opr.top() != '-' && opr.top() != '+' && opr.top() != '(')
                        {
                            BLExp.push_back(opr.top());
                            opr.pop();
                        }
                        else break;
                    }
                }
                opr.push(c);
            }
        }
    }
    while (!opr.empty())
    {
        BLExp.push_back(opr.top());
        opr.pop();
    }

    for (char c : BLExp)
    {
        cout << c;
    }
    cout << endl;

    stack<int> res;
    for (char c : BLExp)
    {
        if (c >= '0' && c <= '9')
        {
            res.push(c - '0');
        }
        else
        {
            if (c == '+')
            {
                int a = res.top();
                res.pop();
                if(!res.empty()){
                    int b = res.top();
                    res.pop();
                    res.push(b + a);
                }
                else{
                    res.push(a);
                }
            }
            else if (c == '-')
            {
                int a = res.top();
                res.pop();
                if(!res.empty()){
                    int b = res.top();
                    res.pop();
                    res.push(b - a);
                }
                else{
                    res.push(-a);
                }
            }
            else if (c == '*')
            {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                res.push(b * a);
            }
            else
            {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                res.push(b / a);
            }
        }
    }
    cout << res.top();
}