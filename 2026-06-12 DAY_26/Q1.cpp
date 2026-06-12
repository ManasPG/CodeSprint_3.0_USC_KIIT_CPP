#include<bits/stdc++.h>
using namespace std;

struct Node{
  long long data;
  Node* next;
  Node* random;

  Node(long long x)
  {
    data=x;
    next=nullptr;
    random=nullptr;
  }
};

Node* cloneList(Node* head){
  if(!head) return nullptr;
  unordered_map<Node*,Node*> mp;
  Node* curr=head;
  while(curr)
    {
      mp[curr]=new Node(curr->data);
      curr=curr->next;
    }

  curr=head;
  while(curr)
    {
      mp[curr]->next=(curr->next ? mp[curr->next]:nullptr);
      mp[curr]->random=(curr->random ? mp[curr->random]:nullptr);
      curr=curr->next;
    }
  return mp[head];
}

int main()
{
  int N;
  cin>>N;
  vector<long long> userID(N);
  for(int i=0;i<N;i++)
    {
      cin>>userID[i];
    }
  vector<int> randomIdx(N);
  for(int i=0;i<N;i++)
    {
      cin>>randomIdx[i];
    }

  vector<Node*> nodes(N);
  for(int i=0;i<N;i++)
    {
      nodes[i]=new Node(userID[i]);
    }
  for(int i=0;i<N-1;i++)
    {
      nodes[i]->next=nodes[i+1];
    }
  for(int i=0;i<N;i++)
    {
      if(randomIdx[i]!=-1)
      {
        nodes[i]->random=nodes[randomIdx[i]];
      }
    }
  Node* head=(N>0?nodes[0]:nullptr);

  Node* clonedHead=cloneList(head);

  vector<Node*> clonedNodes;
  Node* temp=clonedHead;
  
  while(temp)
    {
      clonedNodes.push_back(temp);
      temp=temp->next;
    }

  unordered_map<Node*,int> idxMap;

  for(int i=0;i<(int)clonedNodes.size();i++)
    {
      idxMap[clonedNodes[i]]=i;
    }

  for(int i=0;i<(int)clonedNodes.size();i++)
    {
      cout<<clonedNodes[i]->data<<" ";
      if(clonedNodes[i]->random)
      {
        cout<<idxMap[clonedNodes[i]->random];
      }
      else
      {
        cout<<-1;
      }
      cout<<"\n";
    }
  return 0;
}