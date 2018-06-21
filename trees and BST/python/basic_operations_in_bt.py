class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def print_tree(self, node):
        if node is None:
            return
        print(node.data)
        self.print_tree(node.left)
        self.print_tree(node.right)


if __name__ == '__main__':
    tree = Node(1)
    tree.left = Node(2)
    tree.right = Node(3)
    tree.left.left = Node(4)
    tree.left.right = Node(5)
    tree.print_tree(tree)
