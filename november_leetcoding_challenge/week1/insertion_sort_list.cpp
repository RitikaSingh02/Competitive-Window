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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode * pre=NULL, *cur=head;
        while(cur)
        {
            
            ListNode * temp=cur;
            cur=cur->next;
            if(pre==NULL || pre->val>temp->val)
            { temp->next=pre;
                pre=temp;
            }
            else
            {
                ListNode * s=pre;
                while(s)
                {
                    if(!s->next || s->next->val>temp->val)
                    {temp->next=s->next;
                        s->next=temp;
                        break;
                    }
                    s=s->next;
                }
            }
        }
        return pre;
                
    }
};