#include<cstdio>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int ht[256]={0},ans=0;
struct node{
	int data;
	node* lchild;
	node* rchild;
	
};
struct cmp{   //全局指针节点比较函数
	bool operator()(const node* a,const node* b)const
	{
		return a->data>b->data;
	}
};
priority_queue<node*,vector<node*>,cmp> q;  
node* newNode(int data,node* l,node* r)
{
	node* root=new node;
	root->data=data;
	root->lchild=l;
	root->rchild=r;
	return root;
}
void WPL(node* root,int d)
{
	if(root==NULL) return;
	if(root->lchild==NULL&&root->rchild==NULL)
	{
		ans+=root->data*d;
	}
	WPL(root->lchild,d+1);
	WPL(root->rchild,d+1);
}

int main()
{
	string str;
	cin>>str;
	node* root;
	for(int i=0;i<str.size();i++)
	{
		ht[str[i]]++;
	}
	for(int i=0;i<256;i++)
	{
		if(ht[i]!=0)
		{
			root=newNode(ht[i],NULL,NULL);
			q.push(root);
		}
	}
	while(q.size()>1)
	{
		node* a=q.top();q.pop();
		node* b=q.top();q.pop();
		root=newNode(a->data+b->data,a,b);
		q.push(root);
	}
	printf("%d\n",root->data);
	WPL(root,0);
	printf("%d\n",ans);
	return 0;
}