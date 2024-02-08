

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
public:
    Node *sortedInsert(Node* head, int data)
    {
        Node *newNode = new Node(data);

        // If the linked list is empty, make the new node the head and point it to itself
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }

        // If the new node should be inserted before the head
        if (data < head->data) {
            newNode->next = head;
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            return newNode;
        }

        // Find the position to insert the new node while keeping the list sorted
        Node *temp = head;
        while (temp->next != head && temp->next->data < data) {
            temp = temp->next;
        }

        // Insert the new node at the appropriate position
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
};