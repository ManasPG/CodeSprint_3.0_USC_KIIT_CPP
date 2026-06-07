#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int val;
  Node* next;
  Node(int x)
  {
    val=x;
    next=nullptr;
  }
};

int main()
{
  int n;
  cin>>n;
  cin.ignore();

  vector<Node*> lists;

  for(int i=0;i<n;i++)
    {
      string line;
      getline(cin,line);
      
      stringstream ss(line);

      Node* head=nullptr;
      Node* tail=nullptr;

      int x;
      while(ss>>x)
        {
          Node* newNode=new Node(x);

          if(head==nullptr)
          {
            head=tail=newNode;
          }
          else
          {
            tail->next=newNode;
            tail=newNode;
          }
        }
      lists.push_back(head);

      
    }

  priority_queue<int,vector<int>,greater<>> pq;

  for(auto it:lists)
    {
      while(it)
        {
          pq.push(it->val);
          it=it->next;
        }
    }

  Node* head=nullptr;
  Node* tail=nullptr;

  while(!pq.empty())
    {
      Node* node=new Node(pq.top());
      pq.pop();
      if(head==nullptr)
      {
        head=tail=node;
      }
      else
      {
        tail->next=node;
        tail=node;
        
      }
    }

  Node* temp=head;
  
  while(temp)
    {
      cout<<temp->val<<" ";
      temp=temp->next;
    }


  return 0;

  
  
  
}