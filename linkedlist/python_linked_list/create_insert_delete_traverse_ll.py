class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    head = None

    def __init__(self, node):
        self.head = node

    def insert_at_begin(self, data):
        tmp = Node(data)
        if self.head is None:
            self.head = tmp
        else:
            tmp.next = self.head
            self.head = tmp

    def insert_at_end(self, data):
        newnode = Node(data)
        if self.head is None:
            self.head = newnode
            return
        tmp = self.head
        while tmp.next is not None:
            tmp = tmp.next
        tmp.next = newnode

    def print_list(self):
        tmp = self.head
        while tmp is not None:
            print(tmp.data, end=' ')
            tmp = tmp.next
        print()

    def delete_at_head(self):
        # tmp = self.head
        self.head = self.head.next
        # tmp = None

    def delete_at_end(self):
        curr = self.head
        prev = None
        while curr.next is not None:
            prev = curr
            curr = curr.next
        prev.next = None
        curr = None

    def insert_at_pos(self, data, pos):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        prev, curr, curr_pos = None, self.head, 1
        while curr_pos < pos and curr is not None:
            curr_pos += 1
            prev = curr
            curr = curr.next
        if pos == 1:
            new_node.next = self.head
            self.head = new_node
            return
        new_node.next = prev.next
        prev.next = new_node

    def delete_at_pos(self, pos):
        if self.head is None:
            return
        if pos == 1:
            self.head = self.head.next
            return
        curr_pos, prev, curr = 1, None, self.head
        while curr_pos < pos and curr is not None:
            curr_pos += 1
            prev = curr
            curr = curr.next
        prev.next = prev.next.next
        curr = None

    def nth_element_from_end(self, n):
        tmp = self.head
        while n > 0 and tmp is not None:
            n -= 1
            tmp = tmp.next
        if tmp is None:
            print("List does not have {} elements".format(n))
            return
        curr = self.head
        while tmp is not None:
            curr = curr.next
            tmp = tmp.next
        print("{} element from end is {}".format(n, curr.data))

    def reverseList(self):
        # Code here
        if self.head is None:
            return None
        prev = None
        curr = self.head
        nex = self.head
        while curr is not None:
            nex = curr.next
            curr.next = prev
            prev = curr
            curr = nex
        self.head = prev


def getCount(head):
        # Code here
        tmp = head
        count = 0
        while tmp is not None:
            count += 1
            tmp = tmp.next
        return count


def getNth(head, k):
    # Code here
    curr_pos = 1
    tmp = head
    while curr_pos != k:
        tmp = tmp.next
        curr_pos += 1
    return tmp.data


def findMid(head):
    # Code here
    if head is None:
        return Node(-1)
    slow = head
    fast = head
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next
    return slow


def isCircular(head):
    # Code here
    slow = head
    fast = head
    loop = False
    while fast is not None and fast.next is not None:
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            loop = True
            break

    if loop is True:
        fast = head
    else:
        return False
    while fast != slow:
        fast = fast.next
        slow = slow.next
    if slow == head:
        return True
    else:
        return False


def rotateList(head, k):
    # code here
    if head is None:
        return
    curr = head
    while k > 1:
        k -= 1
        curr = curr.next
    if curr.next is None:
        return head
    nex = curr.next
    while nex is not None and nex.next is not None:
        nex = nex.next
    nex.next = head
    head = curr.next
    curr.next = None
    return head

# Reverse a Linked List in groups of given size


def reverse(head, k):
    # Code here
    curr = head
    prev = None
    nex = None
    cur_pos = 0
    while cur_pos < k and curr is not None:
        nex = curr.next
        curr.next = prev
        prev = curr
        curr = nex
        cur_pos += 1

    if nex is not None:
        head.next = reverse(nex, k)
    return prev


if __name__ == '__main__':
    llist = LinkedList(None)
    print('------here--------')
    llist.insert_at_begin(3)
    llist.insert_at_begin(2)
    llist.insert_at_begin(1)

    llist.print_list()
    llist.delete_at_head()
    llist.print_list()

    llist.insert_at_end(4)
    llist.print_list()

    llist.insert_at_begin(1)
    llist.print_list()

    llist.delete_at_end()
    llist.print_list()

    llist.insert_at_end(5)
    llist.print_list()

    llist.insert_at_begin(0)
    llist.print_list()

    llist.insert_at_pos(1, 1)
    llist.print_list()

    llist.delete_at_pos(2)
    llist.print_list()

    llist.nth_element_from_end(6)
    llist.print_list()