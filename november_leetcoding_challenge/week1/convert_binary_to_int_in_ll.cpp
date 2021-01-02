/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s="";
        ListNode* temp=head;
        while(temp!=NULL)
        {   
            s+=to_string(temp->val);
            temp=temp->next;
        }
        // long long int number=stoi(s);
        int sum=0;
        int i=0;
        int rem=0;
        while(i<s.size())
        {   
            string s1=string(1,s[i]);
            rem=stoi(s1);
            cout<<rem<<"\n";
            // if(rem!=0)
            // {
            sum+=rem*pow(2,s.size()-i-1);
            // }
            i++;
        }
        return sum;
    }
};