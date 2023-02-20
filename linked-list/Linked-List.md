Linked List : It is for storing collections of data.

Feature
    - Successive elements are connected by pointers.
    - The last element points to NULL
    - Can grow or Shrink in size during execution of a program
    - Can be made just as long as required
    - Does not waste memory space

Main ADT
    - Insert
    - Delete

Auxiliary ADT
    - Delete List : Remove all
    - Count
    - Find

Difference between linked lists and arrays
- Array
    - Simple and easy to use
    - Faster access to the elements
    - Fixed Size
    - One block allocation
    - Complex position-based insertion

Singly Linked List

struct ListNode { 
    int data;
    struct ListNode *next;
};

Traversing the Linked List
- Follow the pointers
- Display the contents of the nodes (or count) as they are traversed
- Stop when the next pointer points to NULL

Insert(Delete) Elements in Linked List
- At the beginning
- At the end of the list
- random location

Double Linked List

struct ListNode { 
    int data;
    struct ListNode *next;
    struct ListNode *prev;
};


Traversing -> Circular the Linked List

