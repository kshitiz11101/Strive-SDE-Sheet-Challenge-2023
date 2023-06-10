#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>*MiddleNode(LinkedListNode<int>*head){
     LinkedListNode<int>*slow=head;
      LinkedListNode<int>*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return slow;
    }
LinkedListNode<int>*reverse(LinkedListNode<int>*head){
    if(head==NULL){
        return NULL;
    }
LinkedListNode<int>*curr=head;
LinkedListNode<int>*forward=NULL;
LinkedListNode<int>*prev=NULL;
while(curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
}
return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL){
        return true;
    }
    LinkedListNode<int>*mid=MiddleNode(head);
    LinkedListNode<int>*temp=mid->next;
    mid->next=reverse(temp);
    LinkedListNode<int>*head1=head;
    LinkedListNode<int>*head2=mid->next;
    while(head2!=NULL){
      if (head1->data != head2->data) {
        return false;
      }
        head1=head1->next;
                head2=head2->next;
    }
       temp=mid->next;
            mid->next=reverse(temp);
    return true;

}
