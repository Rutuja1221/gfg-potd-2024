class Solution:
    def sortedInsert(self, head, data):
        # Create a new node with the given data
        new_node = Node(data)
        
        # If the linked list is empty, make the new node the head
        if not head:
            new_node.next = new_node
            return new_node
        
        # If the new node's data is less than the head's data,
        # insert it before the head and update the head
        if data < head.data:
            temp = head
            while temp.next != head:
                temp = temp.next
            temp.next = new_node
            new_node.next = head
            return new_node
        
        # Traverse the linked list to find the correct position to insert the new node
        temp = head
        while temp.next != head and temp.next.data < data:
            temp = temp.next
        
        # Insert the new node after temp
        new_node.next = temp.next
        temp.next = new_node
        
        return head
