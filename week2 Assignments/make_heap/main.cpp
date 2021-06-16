#include <iostream>
#include<vector>
#include <fstream>
using namespace std;
vector<int>v;
vector<int>result;
int leftChild(int i)
{
    return 2*i+1;
}
int rightChild(int i)
{
    return 2*i+2;
}
void siftdown(int i)
{
    int minIndex=i;
    int l=leftChild(i);
    if(l<v.size() && v[l]<v[minIndex])
        minIndex=l;
    int r=rightChild(i);
    if(r<v.size()&&v[r]<v[minIndex])
        minIndex=r;
    if(i!=minIndex){
		result.push_back(i);
		result.push_back(minIndex);
        //cout<<i<<" "<<minIndex<<endl;
        swap(v[i],v[minIndex]);
        siftdown(minIndex);
    }
}
int main()
{

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        v.push_back(x);
    }
    for(int i=(v.size()/2)-1; i>=0; i--)
        siftdown(i);
	cout<<result.size()/2<<endl;
	for(int i=0;i<result.size();i+=2){
		cout<<result[i]<<" "<<result[i+1]<<endl;
	}
    return 0;
}
