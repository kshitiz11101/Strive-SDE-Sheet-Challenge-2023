#include <bits/stdc++.h> 
class Queue {
    int size;

    int *arr;

    int qfront;

    int rear;
public:
    Queue() {
        // Implement the Constructor
        size=100001;

    arr=new int[size];

    qfront=0;

    rear=0;    
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
          if(qfront==rear)

     {

         return true;

     }  

     else

     {

         return false;

     }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
          if(rear!=size)

        {

            arr[rear]=data;

            rear++;

        }
    }

    int dequeue() {
        // Implement the dequeue() function
          if(rear!=qfront)

        {

            int ans=arr[qfront];

            arr[qfront]=-1;

            qfront++;

            if(qfront==rear)

            {

                qfront=0;

                rear=0;

            }

            return ans;

        }

        else

        {

            return -1;

        }
    }

    int front() {
        // Implement the front() function
          if(rear==qfront)

        {

            return -1;

        }

        else

        {

            return arr[qfront];

        }
    }
};
