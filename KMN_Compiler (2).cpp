#include<bits/stdc++.h>
using namespace std;

set<string>tab;

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

    ifstream inFile("input.txt");

    string nextToken;
    while (inFile >> nextToken)
    {
        lexm.push_back(nextToken);
    }
    inFile.close();

    int n=lexm.size();

    deque <string> dt_int, dt_char;

    for(int i=0;i<n;i++)
    {
        if(lexm[i] == "int" && lexm[i+1] != "main()") {
            for(int j = i+1; j < n; j++) {
                if(lexm[j] == ";") {
                    break;
                }
                else if(lexm[j] == "char") {
                    break;
                }
                if(identifier(lexm[j])) {
                    dt_int.push_back(lexm[j]);
                }
            }
        }
        else if(lexm[i] == "char") {
            for(int j = i+1; j < n; j++) {
                if(lexm[j] == ";") {
                    break;
                }
                else if(lexm[j] == "int") {
                    break;
                }
                if(identifier(lexm[j])) {
                    dt_char.push_back(lexm[j]);
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(identifier(lexm[i])) {
            bool flag = false;
            for(int j = 0; j < dt_int.size(); j++) {
                if(dt_int[j] == lexm[i]) {
                    flag = true;
                    break;
                }
            }

            if(flag) {
                if(lexm[i+1] == "=") {
                    string str = lexm[i+2];

                    if(!identifier(str)) {
                        for(int j = 0; j < str.size(); j++) {
                            if(!(str[j] >= 48 && str[j] <= 57)) {
                                cout << "There is an Error in Identifier \"" << lexm[i] << "\"\n";

                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(identifier(lexm[i])) {
            bool flag = false;
            for(int j = 0; j < dt_char.size(); j++) {
                if(dt_char[j] == lexm[i]) {
                    flag = true;
                    break;
                }
            }

            if(flag) {
                if(lexm[i+1] == "=") {
                    string str = lexm[i+2];

                    if(!identifier(str)) {
                        if(str.size() != 3) {
                            cout << "There is an Error in Identifier \"" << lexm[i] << "\"\n";
                            return 0;
                        }
                        else if(str[0] != '\'' && str[2] != '\'') {
                            cout << "There is an Error in Identifier \"" << lexm[i] << "\"\n";
                            return 0;
                        }

                    }
                }
            }
        }
    }

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


    cout << "Tokens\tType\tID\n____________________________________\n\n";
    int cnt = 1;
    for(auto it= tab.begin(); it != tab.end(); ++it) {
        if(identifier(*it)) {
            cout << *it << " -> Identifier " << cnt << endl;
            cnt++;
        }
    }

    for(auto it= tab.begin(); it != tab.end(); ++it) {
        if(keyword(*it)) {
            cout << *it << " -> Keyword" << endl;
        }
        else if(operate(*it)) {
            cout << *it << " -> Operator" << endl;
        }
        else if(seperate(*it)) {
            cout << *it << " -> Separator" << endl;
        }
    }

    return 0;
}
