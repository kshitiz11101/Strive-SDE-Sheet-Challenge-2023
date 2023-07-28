// Stack class.
class Stack {
    
public:
    int top1;
    int *arr;
    int size;
    Stack(int capacity) {
        // Write your code here.
        // st=new int[capacity];
        this->top1=-1;
        this->size=capacity;
        arr=new int[capacity];
    }

     void push(int num) {
           if(size-top1>1){
               top1++;
               arr[top1]=num;
           }
           else{
               return;
           }
        }

        int pop() {
          if(top1>=0){
              top1--;
              return arr[top1+1];
          }
          else{
              return -1;
          }
        }

        int top() {
        if(top1>=0){
            return arr[top1];
        }   
        else{
            return -1;
        }
        }

       int isEmpty() {
            if (top1 == -1) {
                return 1;
            } else {
                return 0;
            }
        }

       int isFull() {
            if (top1 == size - 1) {
                return 1;
            } else {
                return 0;
            }
        }
    
    
};
