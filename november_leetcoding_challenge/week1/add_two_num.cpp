class Solution {
public:

void listtostack(ListNode* head,stack<int> &s)
{
    while(head!=NULL)
    {
        s.push(head->val);
        head=head->next;
    }
    
    return;
}

ListNode* stacktolist(stack<int> s)
{
    ListNode* head=NULL;
    
    ListNode* temp=NULL;
    
    while(s.size())
    {
        int x=s.top();
        s.pop();
        
        ListNode* newnode = new ListNode(x);
        
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
    
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    stack<int> s1;
    stack<int> s2;
    stack<int> ans;
    
    listtostack(l1,s1);
    listtostack(l2,s2);
    
    int carry=0;
    //case 1: if the size of both the ll are equal
    while(s1.size() and s2.size())
    {
        int x=s1.top();
        int y=s2.top();
        
        s1.pop();s2.pop();
        
        int sum=x+y+carry;
        
        ans.push(sum%10);
        
        carry=sum/10;
    }
    //if s1 is of greater size
    while(s1.size())
    {
        int x=s1.top();
        
        s1.pop();
        
        int sum=x+carry;
        
        ans.push(sum%10);
        
        carry=sum/10;
    }
    //if s2 is of greater size
     while(s2.size())
     {
        int x=s2.top();
        
        s2.pop();
        
        int sum=x+carry;
        
        ans.push(sum%10);
        
        carry=sum/10;
     }
    //to check if the last sum resulted a carry of 1 then we need to push it
     if(carry==1)
     {
         ans.push(1);
     }
    
     return stacktolist(ans);
}
};