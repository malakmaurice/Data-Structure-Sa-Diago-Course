#include <iostream>
#include <vector>
#include <list>
#include "algorithm"
#include "fstream"
using namespace std;
#define ll long long
#define p 1000000007
#define x 263
int m=5;
ll pow[16];
void power()
{
    pow[0]=1;
    for(int i=1; i<15; i++)
        pow[i]=((pow[i-1]*x)%p+p)%p;
    /*for(int i=0; i<15; i++)
        cout<<pow[i]<<" ";*/
}
ll hashKey(string s)
{
    ll key=0;
    for(int i=0; i<s.length(); i++)
    {
        key+=s[i]*pow[i];
        //cout<<key<<" ";
    }
    key=(key%p+p)%p;
    key= key % m;
    return key;
}
void showlist(list <string> g)
{
    list <string> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout<<*it<<" " ;
    cout << '\n';
}
int main()
{
    //freopen("input.txt","r",stdin);
    int n,h;
    ll key;
    string query;
    list<string>::iterator it;
    cin>>m>>n;
    vector< list<string> > hashTable(m);
    power();
    while(n--)
    {
        cin>>query;
        if(query.compare("add") ==0)
        {
            cin>>query;
            key =hashKey(query);
            it=find(hashTable[key].begin(),hashTable[key].end(),query);
            if(it==hashTable[key].end())
                hashTable[key].push_front(query);
        }
        else if (query.compare("del") ==0)
        {
            cin>>query;
            key =hashKey(query);
            it=find(hashTable[key].begin(),hashTable[key].end(),query);
            if(it!=hashTable[key].end())
                hashTable[key].erase(it);
        }
        else if(query.compare("find")==0)
        {
            cin>>query;
            key =hashKey(query);
            it=find(hashTable[key].begin(),hashTable[key].end(),query);
            if(it!=hashTable[key].end())
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
        else
        {
            cin>>h;
            showlist(hashTable[h]);
        }
    }
    // showlist(hashTable[4]);
    // hashTable[0].push_front("world");
    //hashTable[0].push_front("hello");
    /* for(unsigned int i=0; i<hashTable.size(); ++i)  // You can access elements calling the operator[].
     {
         for(std::list<string>::iterator it=hashTable[i].begin(); it!=hashTable[i].end(); ++it)
         {
             std::cout<<*it<<' '; // You can access elements calling the operator[] , you need an iterator.
         }
         std::cout<<std::endl;
     }*/
    //showlist(hashTable[0]);
    //cout << hashTable[0] << endl;
    return 0;
}
