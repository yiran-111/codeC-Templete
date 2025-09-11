#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
private:
    int val;

public:
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void print()
    {
        ListNode *cur = this;
        while (cur != NULL)
        {
            if (cur->val != -1)
            {
                cout << cur->val << " ";
            }
            cur = cur->next;
        }
        cout << endl;
    }
    void printElement(int value)
    {
        ListNode *cur = this;
        for (int i = 0; i < value && cur != NULL; i++)
        {
            cur = cur->next;
        }
        if ((cur != NULL) && (value > 0))
            cout << cur->val << endl;
        else
            cout << "Output position out of bounds." << endl;
    }
};
int main()
{
    int n, k, m;
    cin >> n >> k;
    ListNode *head = new ListNode(-1);
    ListNode *dummy = head;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dummy->next = new ListNode(x);
        dummy = dummy->next;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> m;
        head->printElement(m);
    }

    for (dummy = head; dummy != NULL;)
    {
        ListNode *temp = dummy;
        dummy = dummy->next;
        delete temp;
    }
    return 0;
}