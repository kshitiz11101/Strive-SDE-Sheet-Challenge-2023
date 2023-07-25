/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node* result=NULL;

    if (a->data <= b->data) {
        result = a;
        result->child = merge(a->child, b);
    }
    else {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = NULL;
    return result;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if (head == NULL || head->next == NULL)
        return head;

  Node *newLL = flattenLinkedList(head->next);
          head->next = nullptr;
          Node *newHead = merge(newLL, head);

        return newHead;
}
