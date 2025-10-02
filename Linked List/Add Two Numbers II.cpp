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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;

        // l1 er all digit in stack
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // l2 er all digit in stack
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *head = NULL;

        // jotokkhon stack empty na hoi or carry ase
        while (!s1.empty() || !s2.empty() || carry)
        {
            int sum = carry;
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);

            // new node ke shmne attach kori
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};