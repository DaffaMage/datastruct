#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <stdio.h>

char opr[4] = {'+','-','*','/'};
char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

using namespace std;

void LevelControl(int lvl, int pos)
{
    if (lvl>=0)
        cout << lvl;
    else if (lvl==-1)
        cout << endl << "Over-closed Parenthesis at column " << pos << endl;
    else if (lvl==-2)
        cout << endl << "Ending has insufficient parenthesis!" << endl;
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

string ParReBal(string data)
{
    stack<char> S;
    int i;
    for (i=0;i<data.length();i++)
    {
        if (data[i]=='(')
        {
            S.push(data[i]);
        }
        else if (data[i]==')')
        {
            S.pop();
        }
    }

    if (S.empty()==false)
        data.append(")");
    return data;
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
                if (data[i]==opr[j] && (data[i-1]==opr[k] || (i>1 && data[i-1]==' ' && data[i-2]==opr[k] && data[i-2]!=opr[1])))
                {
                    ValReport(i);
                    return false;
                }
            }
        }
    }
    return true;
}

string toString(int x)
{
    string s;
    bool neg = false;
    if (x==0)
    {
        s = (char) ((0) + '0');
        return s;
    }

    if (x<0)
    {
        neg = true;
        x*=-1;
    }

    while (x>0)
    {
        s = (char) ((x%10) + '0') + s;
        x/=10;
    }

    if (neg)
    {
        s = '-' + s;
    }
    return s;
}

string CountData(string data)
{
    //cout << "Evaluating : " << data << endl;
    int i,j,alpha=0,beta=0,res=0;
    char op;
    bool isOpFill = false, alphaNeg = false, betaNeg = false;
    for (i=0;i<data.length();i++)
    {
        if (data[i]==opr[1])
        {
            if (alpha==0 && alphaNeg==false)
            {
                alphaNeg = true;
                continue;
            }
            if (beta==0 && isOpFill == true)
            {
                betaNeg = true;
                continue;
            }
        }

        for (j=0;j<10;j++)
        {
            if (data[i]==num[j])
            {
                if (!isOpFill)
                    alpha = alpha*10 + j;
                else
                    beta = beta*10 + j;
            }
        }

        for (j=0;j<4;j++)
        {
            if (data[i]==opr[j])
            {
                op = opr[j];
                //cout << op << endl;
                isOpFill = true;
            }
        }
    }

    if (alphaNeg)
        alpha*=-1;

    if (betaNeg)
        beta*=-1;

    switch (op)
    {
        case '+' : res = alpha + beta;break;
        case '-' : res = alpha - beta;break;
        case '*' : res = alpha * beta;break;
        case '/' : res = alpha / beta;break;
        default : res = alpha + beta;break;
    }
    cout << alpha << op << beta << " = " << res << endl;
    getchar();
    data.erase();
    data = toString(res);
    //cout << data << endl;
    getchar();

    return data;
}

void ShowStack(string datapiece)
{
    int i, x;
    stack <char> S;
    cout << "Current Stack Form : " << endl;
    for (i=0;i<datapiece.length();i++)
    {
        S.push(datapiece[i]);
        cout << "Reading : " << datapiece[i] << endl;
        getchar();
    }
    cout << endl;
}

string FakeStack(string data)
{
    return "(" + data;
}

string PriorityCheck(string data)
{
    string temp1, temp2, temp3;
    int i,j,lnum=0,rnum=0,opos=0, INF=999;
    bool htf = false;
    stack <char> S;
    for (i=0;i<data.length();i++)
    {
        ///Get the area of check
        if (data[i]=='(')
        {
            S.push(i);
        }
        if (data[i]==')')
        {
            S.pop();
        }
        ///Search for higher tier
        if ((data[i]=='*' || data[i]=='/') && S.size()==1)
        {
            opos = i;
            htf = true;
        }
        ///Number Check
        for (j=0;j<10;j++)
        {
            if (data[i]==num[j])
            {
                if (!htf)
                    lnum = i;
                else
                    rnum = i;
            }
        }
        if (rnum)
            break;
    }
    //cout << "Get Position : " << lnum << "," << rnum;
    //cout << endl;
    temp1 = data.substr(lnum,rnum-lnum+1);
    temp2 = data.substr(0,lnum);
    temp3 = data.substr(rnum+1, INF);
    //cout << temp2 << " " << temp1 << " " << temp3 << endl;
    data = temp2 + "(" + temp1 + ")" + temp3;
    //cout << data << endl;

    return data;
}

string MultiCheck(string data)
{
    string temp1, temp2, temp3;
    stack <int> S,T;
    int i,j,opr=0,firstloc,lnum=0,rnum=0, INF=999;
    bool htf;
    for (i=0;i<data.length();i++)
    {
        ///Operator at stack level
        if (data[i]=='+' || data[i]=='-' || data[i]=='*' || data[i]=='/')
        {
            opr++;
            if (opr==1)
            {
                firstloc = i;
                htf = true;
            }
        }
        ///Get the area of check
        if (data[i]=='(')
        {
            T.push(firstloc);
            S.push(opr);
            opr = 0;
            firstloc = 0;
        }
        if (data[i]==')')
        {
            opr = S.top();
            firstloc = T.top();
            S.pop();
            T.pop();
        }
        ///Number Check
        for (j=0;j<10;j++)
        {
            if (data[i]==num[j])
            {
                if (!htf)
                    lnum = i;
                else
                    rnum = i;
            }
        }
        if (opr>1)
            break;
    }
    temp1 = data.substr(lnum,rnum-lnum+1);
    temp2 = data.substr(0,lnum);
    temp3 = data.substr(rnum+1, INF);
    //cout << temp2 << " " << temp1 << " " << temp3 << endl;
    data = temp2 + "(" + temp1 + ")" + temp3;
    return data;
}

string CountAll(string data)
{
    int i,j,istart,iend, operation_set=0;
    stack <char> S;
    string tempdata;
    //cout << "Current Form : " << data << endl;
    data = ParReBal(data);
    //cout << "Proper Current Form : " << data << endl;

    for (i=0;i<=data.length();i++)
    {
        //cout << "Position : " << i << " " << data[i] << endl;
        for (j=0;j<4;j++)
        {
            if (data[i]==opr[j])
                operation_set++;
        }
        ///STACK PUSH
        if (data[i]=='(')
        {
            operation_set = 0;
            S.push(i);
        }
        ///POPPING
        if (data[i]==')' || operation_set>1)
        {
            istart = S.top();
            iend = i-S.top();
            //cout << iend << endl;
            tempdata = data.substr(0,iend+istart);
            ShowStack(tempdata);
            if (data[i]!=')')
            {
                iend = iend-1;
                istart++;
            }
            cout << "Evaluating : " << tempdata << endl;
            tempdata = data.substr(istart,iend);
            tempdata = CountData(tempdata);
            iend++;
            data.replace(istart,iend,tempdata);
            S.pop();
            break;
        }
    }
    if (!S.empty())
    {
        while (!S.empty())
        {
            S.pop();
        }
        return CountAll(data);
    }
    else
    {
        data = FakeStack(data);
        ShowStack(data);
        cout << "Evaluate : " << data.substr(istart,iend) << endl;
        data = tempdata;
        return data;
    }
}

bool isDataAtZero(string data)
{
    stack<char> S;
    int i;
    for (i=0;i<data.length();i++)
    {
        if (data[i]=='(')
        {
            S.push(i);
            continue;
        }
        else if (data[i]==')')
        {
            S.pop();
            continue;
        }
        if (S.size()==0)
        {
            return true;
        }
    }
    return false;
}

int GetHierarchy(string data)
{
    int i, total=0;
    for (i=0;i<data.length();i++)
    {
        if (data[i]=='*' || data[i]=='/')
            total++;
    }
    return total;
}

int main()
{
    //char input[70];
    int i;
    string data, tempdata;

    cout << "Input : " << endl;
    //cin.getline(input, sizeof(input));
    //data = input;
    getline(cin, data);

    if (ParBalance(data,true))
        {
            cout << endl << "Balanced" << endl;
            if (Valid(data))
            {
                cout << "Valid Equation" << endl;
                for (i=0;i<GetHierarchy(data);i++)
                    data = PriorityCheck(data);///Prioritization
                data = MultiCheck(data);///One by one
                tempdata = data;
                if (data[0]!='(' || data[data.length()-1]!=')' || isDataAtZero(data))
                {
                    data.insert(0,"(");
                    data.insert(data.length(), ")");
                    cout << "To properly count the equation, the formula has been reformed into : " << data << endl << endl;
                }
                cout << "The final result is : " << CountAll(data);
            }
        }
    else
        cout << "Not Balanced" << endl;

    return 0;
}
