// Merge k sorted linked lists and return it as one sorted list.

//     Example :

//     1->10->20 
//     4->11->13
//      3->8->9 
//      will result in

//     1->3->4->8->9->10->11->13->20

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}   
};

ListNode mergeKLists(vector<ListNode *> &A)
{
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
    int k = A.size();
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    for (int i = 0; i < k; ++i)
    {
        if (A[i])
            pq.push({A[i]->val, A[i]});
    }
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        temp->next = it.second;
        temp = temp->next;
        if (it.second->next)
        {
            pq.push({it.second->next->val, it.second->next});
        }
    }
    return dummy->next;
}
