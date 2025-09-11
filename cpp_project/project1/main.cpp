#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
private:
    int val;

public:
    int length = 0;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void insertToN(int x, int n)
    {
        ListNode *newNode = new ListNode(x);
        ListNode *temp = this;
        // 循环 n-1 次找到插入点的前一个节点
        for (int i = 0; i < n - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        // 如果temp为空，说明n过大，但这个检查在main中做更合适
        if (temp == NULL)
            return;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteM(int m)
    {
        ListNode *temp = this;
        // 循环 m-1 次找到删除点的前一个节点
        for (int i = 0; i < m - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        // 检查前一个节点和要删除的节点是否存在
        if (temp == NULL || temp->next == NULL)
            return;

        ListNode *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
    // 从该节点往后打印链表
    void printList()
    {
        ListNode *temp = this->next; // 跳过哨兵节点
        if (temp == NULL)            // 如果链表为空，根据题目要求可能不打印
        {
            // cout << endl; // 如果空链表需要打印空行，则取消此行注释
            return;
        }
        while (temp != NULL)
        {
            cout << temp->val;      // 先打印值
            if (temp->next != NULL) // 如果不是最后一个节点
            {
                cout << " "; // 才打印空格
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
void createList(int k, ListNode *head)
{
    ListNode *temp = head;
    int x;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        ListNode *newNode = new ListNode(x);
        temp->next = newNode;
        temp = temp->next;
        head->length++;
    }
}
int main()
{
    int k, S, x, i, n, L, m;
    cin >> k;
    ListNode *head = new ListNode(-1); // 创建一个哨兵节点
    createList(k, head);
    cin >> S;
    for (i = 0; i < S; i++)
    {
        cin >> n >> x;
        // 2. 先判断，再操作。注意插入位置可以是 length + 1
        if (n <= 0 || n > head->length + 1)
        {
            cout << "Insertion position is invalid." << endl;
        }
        else
        {
            head->insertToN(x, n);
            head->length++;
            head->printList();
        }
    }
    cin >> L;
    for (i = 0; i < L; i++)
    {
        cin >> m;
        // 3. 先判断，再操作。删除位置必须在 [1, length] 之间
        if (m <= 0 || m > head->length)
        {
            cout << "Deletion position is invalid." << endl;
        }
        else
        {
            head->deleteM(m);
            head->length--;
            // 4. 根据题目要求，删除后如果为空，则不打印
            if (head->length > 0)
            {
                head->printList();
            }
        }
    }
    return 0;
}