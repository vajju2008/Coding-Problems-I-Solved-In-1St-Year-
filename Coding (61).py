class Node:
    def__init__(self,data):
        self.data = data
        self.next = none

class Queue:
    def__init__(self):
        self.front = self.rear = None
    def insert(self,value):
        new_node = Node(value)

        if self.rear is None:
            self.front = self.rear = new_Node

        else:
            self.rear.next = new_Node
            self.rear = new_Node

    def delete(self):
        if self.front is None:
            print("Queue is empty")
