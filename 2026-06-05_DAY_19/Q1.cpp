#include<bits/stdc++.h>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x)
  {
    val=x;
    next=nullptr;
  }
};

ListNode* del(ListNode* head,int k)
{
  if(k==1)
  {
    while(head!=head->next)
      {
        ListNode* temp=head;
        ListNode* last=head;

        while(last->next!=head)
          last=last->next;

        head=head->next;
        last->next=head;
        delete temp;
      }
  return head;
  }

  ListNode* curr=head;
  ListNode* prev=nullptr;
  while(curr!=curr->next){
    for(int i=1;i<k;i++)
      {
        prev=curr;
        curr=curr->next;
      }

    prev->next=curr->next;

    ListNode* temp=curr;
    curr=curr->next;
    if(temp==head)
    {
      head=curr;
    }
    delete temp;
  }
  return curr;
}

int main()
{
  int n;
  cin>>n;
  ListNode* head=nullptr;
  ListNode* tail=nullptr;
  
  for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      ListNode* node=new ListNode(x);
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
  tail->next=head;
  int k;
  cin>>k;
  
  ListNode* ans=del(head,k);

  cout<<ans->val;
  return 0;
}