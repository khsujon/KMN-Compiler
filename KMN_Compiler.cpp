#include<bits/stdc++.h>
using namespace std;



bool keyword(string s)
{
    vector<string> v = {"scanf","printf","auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int vsize = v.size();

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i = 0; i < vsize; i++)
    {
        if(s == v[i])
        {
            return true;
        }
    }
    return false;
}

bool identifier(string s)
{
    int size = s.size();
    if(size>23)
    {
        return false;
    }
    if(!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_')||keyword(s)==true)
    {
        return false;
    }
    for(int i = 1; i < size; i++)
    {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
        {
            return false;
        }
    }
    return true;
}

bool operate(string s)
{
    vector<string>op{"+","*","/","%","=",">","<","==","!=",">=","<=","&&","||","!","&","|","^","~",">>","<<","++","--","+=","-=","*=","/=","%="};

    for(int i=0; i<op.size(); i++)
    {

        if(s==op[i])
        {
            return true;

        }
    }
    return false;
}
bool seperate(string s)
{
    vector<string>sept{",",";","(",")","{","}","[","]"};

    for(int i=0; i<sept.size(); i++)
    {

        if(s==sept[i])
        {
            return true;

        }
    }
    return false;
}

int main()
{

    vector<string>lexm;
    vector<string>key;
    vector<string>ident;
    vector<string>sep;
    vector<string>op;

    set<string>tab;

    ifstream inFile("input.txt");

    string nextToken;
    while (inFile >> nextToken)
    {
        lexm.push_back(nextToken);
    }
    inFile.close();

    int n=lexm.size();

    for(int i=0;i<n;i++)
    {
        tab.insert(lexm[i]);
        cout<<"\""<<lexm[i]<<"\""<<endl;
    }
    cout<<"___________________________________________________________________________________________________"<<"\n\n";

    for(int i=0; i<n; i++)
    {

        if(keyword(lexm[i]))
        {
            key.push_back(lexm[i]);

        }
        if(identifier(lexm[i]))
        {
            ident.push_back(lexm[i]);
        }

        if(operate(lexm[i]))
        {
            op.push_back(lexm[i]);
        }
        if(seperate(lexm[i]))
        {
            sep.push_back(lexm[i]);
        }
    }
    cout<<"Keywords Are: "<<endl;

    for(int i=0; i<key.size(); i++)
    {

        cout<<"\""<<key[i]<<"\""<<endl;
    }
    cout<<"___________________________________________________________________________________________________"<<"\n\n";

    cout<<"Identifiers Are: "<<endl;
    for(int i=0; i<ident.size(); i++)
    {

        cout<<"\""<<ident[i]<<"\""<<endl;
    }
    cout<<"___________________________________________________________________________________________________"<<"\n\n";
    cout<<"Operators Are: "<<endl;
    for(int i=0; i<op.size(); i++)
    {

        cout<<"\""<<op[i]<<"\""<<endl;
    }
    cout<<"___________________________________________________________________________________________________"<<"\n\n";

    cout<<"Separators Are: "<<endl;
    for(int i=0; i<sep.size(); i++)
    {

        cout<<"\""<<sep[i]<<"\""<<endl;
    }
    cout<<"___________________________________________________________________________________________________"<<"\n\n";



    for(auto it= tab.begin(); it != tab.end(); ++it)
        cout << ' ' << *it;


    return 0;
}
