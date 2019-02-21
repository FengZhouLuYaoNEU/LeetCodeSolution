class MyLinkedList {
public:
    struct Node
    {
      int val;
      Node * next;
      Node(int val_):val(val_),next(NULL)
      {
      }
    };
    /** Initialize your data structure here. */
    MyLinkedList():head(NULL),tail(NULL),size(0) {
        
    }
    ~MyLinkedList(){
        while (head)
        {
            Node * tmp = head->next;
            delete head;
            head = tmp;
        }
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size || index < 0)
        {
            return -1;
        }
        Node * tmp = head;
        int count = 0;
        while (tmp)
        {
            if (count == index)
            {
                break;
            }
            tmp = tmp->next;
            count++;
        }
        if (tmp)
        {
            return tmp->val;
        }
        else
        {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (head)
        {            
            Node * newHead = new Node(val);
            newHead->next = head;
            head = newHead;
        }
        else
        {
            head = new Node(val);
            tail = head;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (tail)
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        else
        {
            tail = new Node(val);
            head = tail;
        }
        size++;   
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size || index < 0)
        {
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        Node * newNode = new Node(val);
        Node * tmp = head;
        int count = 0;
        while (tmp)
        {
            if (count == index - 1)
            {
                break;
            }
            tmp = tmp->next;
            count++;
        }
        if (tmp)
        {
           Node * tmpNext = tmp->next;
           tmp->next = newNode;
           newNode->next = tmpNext;
        }

        size++;      
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
        {
            return;
        }
        Node * tmp = head;
        int count = 0;
        if (index == 0 && size == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return;
        }else if (index == 0)
        {
            head = tmp->next;
            delete tmp;
            size--;
            return;
        }
        while (tmp)
        {
            if (count == index - 1)
            {
                break;
            }
            tmp = tmp->next;
            count++;
        }
        Node * delNode = tmp->next;
        Node * delNext = delNode->next;
        delete delNode;
        tmp->next = delNext;
        if (tmp->next == NULL)
        {
          tail = tmp;
        }
        size--;
    }
private:
    Node * head;
    Node * tail;
    int    size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
