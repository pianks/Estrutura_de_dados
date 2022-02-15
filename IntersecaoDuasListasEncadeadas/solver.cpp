#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *readList()
{
  int n;
  cin >> n;
  ListNode *head;
  for (int i = 0; i < n; i++)
  {
    ListNode *ptr;
    int x;
    cin >> x;
    if (i == 0)
    {
      head = new ListNode(x);
      ptr = head;
    }
    else
    {
      ptr->next = new ListNode(x, nullptr);
      ptr = ptr->next;
    }
  }

  return head;
}

ListNode *intersectionList(ListNode *head1, ListNode *head2)
{
  bool isEmpty = true;

  ListNode *head, *ptr;

  while (head1 != nullptr and head2 != nullptr) {
    if (head1->val < head2->val) {
      head1 = head1->next;
    } else if (head1->val > head2->val) {
      head2 = head2->next;
    } else {
      int value = head1->val;

      if (isEmpty) {
        isEmpty = false;
        head = new ListNode(value);
        ptr = head;
      } else {
        ptr->next = new ListNode(value, nullptr);
        ptr = ptr->next;
      }

      while (head1 != nullptr and head1->val == value) {
        head1 = head1->next;
      }
      while (head2 != nullptr and head2->val == value) {
        head2 = head2->next;
      }
    }
  }

  return head;
}

void printList(ListNode *head)
{
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    cout << ptr->val << endl;
}

int main()
{

  ListNode *head1 = readList();
  ListNode *head2 = readList();

  ListNode *res = intersectionList(head1, head2);

  printList(res);

  return 0;
}