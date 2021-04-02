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
// https://leetcode.com/submissions/detail/475453501/?from=explore&item_id=3693
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        string front = "";
        
        ListNode * temp = head;
        while( temp  != NULL)
        {
            front+=to_string(temp->val);
            temp= temp->next;
        }
        cout<<front;
        string back = front;
        
        reverse(front.begin(), front.end());
        if(front==back)
            return true;
        else
            return false;
    }
};