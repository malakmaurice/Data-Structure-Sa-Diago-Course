#include <iostream>
#include<stack>
#include<string>
using namespace std;
typedef struct Bracket{
char type;
int position;
}bracket;

int main()
{
    stack<bracket> brackets;
     bracket b;
     bracket close_bracket;
    string text;
    int flag=0;
    char c,close;
    cin>>text;
    for(int i=0; i<text.length(); i++)
    {
        c=text[i];
        if(c=='('||c=='{'||c=='[')
        {
            b.position=i;
            b.type=c;
            brackets.push(b);
        }
        else if(c==')'||c=='}'||c==']')
        {
            if(brackets.empty())
            {
               cout<<i+1;
                return 0;
            }
            close_bracket=brackets.top();
            close=close_bracket.type;
            brackets.pop();
            if((close=='(' && c!=')')||(close=='['&&c!=']')||close=='{'&&c!='}')
            {
                cout<<i+1;
                return 0;
            }

        }
    }
    if(!brackets.empty()){

        while(brackets.size()>1)brackets.pop();
cout<<brackets.top().position+1;
    }
    else cout<<"Success";
    return 0;
}
