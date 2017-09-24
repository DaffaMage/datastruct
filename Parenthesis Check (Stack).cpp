#include <iostream>
#include <stack>
#include <string>

using namespace std;

char opr[4] = {'+','-','*','/'};
char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

void LevelControl(int lvl, int pos)
{
    if (lvl>=0)
        cout << lvl;
    else if (lvl==-1)
        cout << endl << "Invalid Level at column " << pos << endl;
    else if (lvl==-2)
        cout << endl << "Ending not closed" << endl;
}

bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')') return true;
}

bool ParBalance(string data,bool control)
{
    stack<char> S;
    int level=0,i;
    for (i=0;i<data.length();i++)
    {
        if (data[i]=='(')
        {
            S.push(data[i]);
            level++;
        }
        else if (data[i]==')')
        {
            if(S.empty() || !ArePair(S.top(),data[i]))
            {
                if (control==true)
                    LevelControl(-1,i+1);
                return false;
            }
            else
            {
                level--;
                S.pop();
            }
        }
        if (control==true)
            LevelControl(level,i+1);
    }

    if (S.empty()==false && control==true) LevelControl(-2,i+1);
    return S.empty() ? true:false;
}

void ValReport(int i)
{
    cout << endl << "Error in equation at column " <<i;
}

bool Valid(string data)
{
    for(int i=1;i<data.length();i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                if (data[i]==opr[j] && (data[i-1]==opr[k] || (i>1 && data[i-2]==opr[k])))
                {
                    ValReport(i);
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    char input[70];
    string data;

    cout << "Input : " << endl;
    cin.getline(input, sizeof(input));
    data = input;

    if (ParBalance(data,true))
        {
            cout << "Balanced" << endl;
            if (Valid(data))
                cout << "Valid Equation" << endl;
        }
    else
        cout << "Not Balanced" << endl;

    return 0;
}
