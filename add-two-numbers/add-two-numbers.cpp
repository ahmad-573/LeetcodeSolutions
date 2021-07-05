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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* tmp;
        int arr[110];
        for (int i = 0;i<100;i++)
            arr[i] = 0;
        ListNode* head;
        if (tmp1->val + tmp2->val < 10)
        {
            head = new ListNode(tmp1->val + tmp2->val);
        }
        else
        {
            arr[1]++;
            head = new ListNode((tmp1->val + tmp2->val)%10);
        }
        tmp = head;
        int i = 1;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
        while(tmp1 != NULL && tmp2 != NULL)
        {
            ListNode* newNode;
            int number = arr[i]+tmp1->val+tmp2->val;
            if (number < 10)
            {
                newNode = new ListNode(number);
            }
            else
            {
                arr[i+1]++;
                newNode = new ListNode(number%10);
            }
            tmp->next = newNode;
            tmp = newNode;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
            i++;
        }
        if (tmp2 != NULL)
            tmp1 = tmp2;
        
        if (tmp1 != NULL)
        {
            while(tmp1 != NULL)
            {
                ListNode* newNode;
                int number = tmp1->val + arr[i];
                if (number < 10)
                {
                    newNode = new ListNode(number);
                }
                else
                {
                    arr[i+1]++;
                    newNode = new ListNode(number%10);
                }
                tmp->next = newNode;
                tmp = newNode;
                i++;
                tmp1 = tmp1->next;
            }
        }
        if (arr[i] == 1)
        {
            ListNode* newNode = new ListNode(1);
            tmp->next = newNode;
        }
        return head;
    }
};