/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include<unordered_map>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
     unordered_map< Node * , int > mapping ;

 

    Node * head1 = firstHead;

    Node * head2 = secondHead;

 

    while(head1!=NULL){

        mapping[head1]++;

        if(mapping[head1]>1){

            return head1;

        }

        head1=head1->next;

    }

      

    while(head2!=NULL){

        mapping[head2]++;

        if(mapping[head2]>1){

            return head2;

        }

        head2=head2->next;

    }

 

    return NULL;
}
