//cpp code for general trie implementation
                                                                 
                                                                 
 //author rhythmicankur
                                                                 
                                                                 
                                                                
                                                              
#include<bits/stdc++.h>
using namespace std;

struct trienode
{
	struct trienode *children[26];
	
};

struct trienode *root;

string s,fi;


struct trienode *getnode()
{
	struct trienode *pnode=new trienode;   
	
	for(int i=0;i<26;i++)
	pnode->children[i]=NULL;
	
	return pnode;
};

void insert()
{
	struct trienode *pcrawl=root;
	for(int i=0;i<s.length();i++)
	{
		int index=s[i]-'a';
		if(!pcrawl->children[index]){
			
			pcrawl->children[index]=getnode();
			
		}
		
		pcrawl=pcrawl->children[index];
		
	}
	

	
}

bool search()
{
	trienode *curr=root;
	for(int i=0;i<fi.length();i++)
	{
		int index=fi[i]-'a';
		
		if(curr->children[index]==NULL)
		return false;
		
		else
		curr=curr->children[index];
	}
	
	return true;
}



signed main()

{
  
  int n,q;  
  cin>>n>>q;
  root=getnode();   
  while(n--)
  {
  	cin>>s;
  	
    //to build the trie
  	
    insert();
  }
  while(q--)
  {
  	cin>>fi;   
    
    //to check any prefix matches with given string or not
  	
    
    bool ans=search();
  	
  	cout<<ans<<'\n';
  }


return 0;
}
