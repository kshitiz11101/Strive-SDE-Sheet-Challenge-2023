Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    if(l1==NULL)	return l2;
    else if(l2==NULL)	return l1;
    Node*temp=new Node(0);
    Node*cur=temp;
    Node*p=l1,*q=l2;
    int carry=0;
    while(p!=NULL || q!=NULL){
        int x=p!=NULL?p->data:0;
        int y=q!=NULL?q->data:0;
        int sum=x+y+carry;
        cur->next=new Node(sum%10);
        cur=cur->next;
        carry=sum/10;
        if(p!=NULL)	p=p->next;
        if(q!=NULL) q=q->next;
    }
    if(carry>0)
        cur->next=new Node(carry);
    return temp->next;
}
