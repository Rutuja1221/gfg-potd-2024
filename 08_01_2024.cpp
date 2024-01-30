//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
public:
    struct Node *reverseLinkedList(struct Node *head)
    {
        struct Node *prev = NULL;
        struct Node *current = head;
        while (current != NULL)
        {
            struct Node *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }

    struct Node *mergeResult(struct Node *node1, struct Node *node2)
    {
        // Reverse both linked lists
        struct Node *reversed_h1 = reverseLinkedList(node1);
        struct Node *reversed_h2 = reverseLinkedList(node2);

        // Merge the reversed linked lists in non-increasing order
        struct Node *merged_head = NULL;
        struct Node *merged_tail = NULL;

        while (reversed_h1 != NULL || reversed_h2 != NULL)
        {
            struct Node *temp = NULL;
            if (reversed_h1 == NULL)
            {
                temp = reversed_h2;
                reversed_h2 = reversed_h2->next;
            }
            else if (reversed_h2 == NULL)
            {
                temp = reversed_h1;
                reversed_h1 = reversed_h1->next;
            }
            else if (reversed_h1->data >= reversed_h2->data)
            {
                temp = reversed_h1;
                reversed_h1 = reversed_h1->next;
            }
            else
            {
                temp = reversed_h2;
                reversed_h2 = reversed_h2->next;
            }

            if (merged_head == NULL)
            {
                merged_head = temp;
                merged_tail = temp;
            }
            else
            {
                merged_tail->next = temp;
                merged_tail = temp;
            }
        }

        return merged_head;
    }
};




//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends