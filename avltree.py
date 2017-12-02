from bintree import BinTree


class AVLTree(BinTree)
    """
    https://en.wikipedia.org/wiki/AVL_tree
    """
    def __init__(self, value):
        super().__init__(value)
        self.balance = 0

    def insert(self, value):
        super().insert(value)
        self.check_and_rotate()
        return self  # if self.value == value

    def remove(self, value):
        super().remove(value)
        self.check_and_rotate()
        return self

    def check_and_rotate(self):
        rc = self.right_child.depth() if self.right_child else 0
        lc = self.left_child.depth() if self.left_child else 0
        self.balance = rc - lc
        if abs(balance) > 1:
            self.rotate()
        return self

    def rotate(self):
        if self.balance < -1:
            pass
        elif self.balance > 1:
            pass
