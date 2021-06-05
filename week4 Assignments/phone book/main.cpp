#include <iostream>
#include<map>
#include <fstream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    map<int,string> phoneBook;
    int n,num;
    string str;
    map<int,string> ::iterator t;
    cin >>n;
    while(n--)
    {
        cin>>str>>num;
        if(str.compare("add") == 0)
        {
            cin>>str;
            t =phoneBook.find(num);
            if(t!=phoneBook.end())
                phoneBook[num]=str;
            else
                phoneBook.insert(make_pair(num,str));
        }
        else if(str.compare("del") == 0)
        {
            t =phoneBook.find(num);
            if(t!=phoneBook.end())
                phoneBook.erase(num);
        }
        else
        {
            t =phoneBook.find(num);
            if(t!=phoneBook.end())
                cout<<phoneBook[num]<<endl;
            else
                cout<<"not found\n";

        }
    }

    return 0;
}
