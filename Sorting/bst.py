# https://www.geeksforgeeks.org/binary-search-tree-in-python/#

class Tree:

    def __init__(self,val = None):
        self.value = val
        if self.value:
            self.left = Tree()
            self.right = Tree()
        else:
            self.value = None
            self.right = None 
            self.left = None
    
    
    # Check if the node is empty (has no value)
    def isempty(self):
        return (self.value == None)
    
    def isLeaf(self):
        #Check if the tree node is a Leaf node (both left and right children are None)
        if self.left.left == None and self.right.right == None:
            return True
        else:
            return False
    
    def maxval(self):
        #Check if the node is a left node (no children)
        if self.right.right == None:
            return (self.value)
        else:
            return (self.right.maxval())
    
    # Insert a new value into the tree
    def insert(self,data):
      
        # If the node is empty, insert the data here
        if self.isempty():
            self.value = data
            
            # Create left and right children 
            #for the inserted node
            self.left = Tree()
            self.right = Tree()
            print("{} is inserted successfully".format(self.value))
            
        # If data is less than current node value, 
        #insert into left subtree
        elif data < self.value:
            self.left.insert(data)
            return
          
        # If data is greater than current node value, 
        #insert into right subtree
        elif data > self.value:
            self.right.insert(data)
            
        # If data is equal to current node value, do nothing
        elif data == self.value:
            return
        
    def Delete(self,v):
        #Delete a value from the Tree
        if self.isempty():
            return
        if v < self.value:
            self.left.Delete(v)
            return
        if v > self.value:
            self.right.Delete(v)
        
        if v == self.value:
            if self.isLeaf():
                self.value = None
                self.left = None
                self.right = None
                return 

            elif self.left.isempty():
                self.value = self.right.value
                self.left = self.right.left 
                self.right = self.right.right
                return
            else:
                self.value = self.left.maxval()
                self.left.Delete(self.left.maxval())
                return

    def find(self,v):
        if self.isempty():
            #If the tree is empty, the value isn't found
            print("{} is not found".format(v))
            return False
        if self.value == v:
            # If the value is found at current node,
            # print a message and return True
            print("{} is found".format(v))
            return True
        if v < self.value:
            return self.left.find(v)
        else:
            return self.right.find(v)
        
    def inorder(self):
        if self.isempty():
            #If the tree is empty, return an empty list
            return []
        else:
            return self.left.inorder() + [self.value] + self.right.inorder()
        


# Create a tree with root value 15
t = Tree(15)
# Insert some values into the tree
t.insert(10)
t.insert(18)
t.insert(4)
t.insert(11)
t.insert(16)
t.insert(20)
t.insert(13)
print("Before deleting 4: ")
print(t.inorder())
t.Delete(18)
print("After deleting 4: ")
print(t.inorder())


