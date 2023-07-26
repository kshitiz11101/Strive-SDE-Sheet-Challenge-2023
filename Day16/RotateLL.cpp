Node *rotate(Node *head, int k) {
  // Write your code here.
         if(head ==NULL || head->next == NULL || k==0) return head;
		 int count=1;
		 Node* temp = head;
		 while(temp->next != NULL){
			 temp = temp ->next;
			 count++;
		 }

		 temp->next = head;
		 k = k % count;
		 k = count - k;
		 
		 while(k--) temp = temp->next;

		 head = temp ->next;
		 temp->next = NULL;
	return head;

}
