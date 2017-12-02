class BinTree(object):
    """
    Non self balancing Binary Tree
    """
    def __init__(self, value=None):
        self.left_child = None
        self.right_child = None
        self.value = value

    def __len__(self):
        return self.length()

    def has_children(self):
        return self.left_child or self.right_child

    def insert_many(self, *values):
        for v in values:
            self.insert(v)

    def insert(self, value):
        if not self.value:
            self.value = value
            return self
        elif value > self.value:
            if self.right_child is None:
                self.right_child = BinTree(value)
                return self.right_child
            else:
                self.right_child.insert(value)
        elif value < self.value:
            if self.left_child is None:
                self.left_child = BinTree(value)
                return self.left_child
            else:
                self.left_child.insert(value)
        return self  # if self.value == value

    def search(self, value):
        if value == self.value:
            return self
        elif value > self.value and self.right_child:
            return self.right_child.search(value)
        elif value < self.value and self.left_child:
            return self.left_child.search(value)
        return -1

    def remove(self, value):
        if value == self.value:
            if self.has_children():  # this guarantees at least one child
                rc = self.right_child.depth() if self.right_child else 0
                lc = self.left_child.depth() if self.left_child else 0
                if rc > lc or self.left_child is None:
                    self.value = self.right_child.minimum().value
                    self.right_child.remove(self.value)
                else:
                    self.value = self.left_child.maximum().value
                    self.left_child.remove(self.value)
            else:
                # Set it to None and purge it in higher recurrency level.
                self.value = None
        elif value > self.value:
            if self.right_child:
                self.right_child.remove(value)
        elif value < self.value:
            if self.left_child:
                self.left_child.remove(value)
        # Purging Nones
        if self.left_child is not None and self.left_child.value is None:
            self.left_child = None
        if self.right_child is not None and self.right_child.value is None:
            self.right_child = None
        return self

    def length(self):
        if not self.value:
            return 0
        res = 1
        if self.left_child:
            res += self.left_child.length()
        if self.right_child:
            res += self.right_child.length()
        return res

    def depth(self):
        if not self.value:
            return 0
        lvl, lc, rc = 1, 0, 0
        if self.left_child:
            lc += self.left_child.depth()
        if self.right_child:
            rc += self.right_child.depth()
        return lvl + max(lc, rc)

    def minimum(self):
        if self.left_child is None:
            return self
        return self.left_child.minimum()

    def maximum(self):
        if self.right_child is None:
            return self
        return self.right_child.maximum()

    def to_dict(self):
        repr = {'value': self.value}
        if self.right_child:
            repr['right_child'] = self.right_child.to_dict()
        if self.left_child:
            repr['left_child'] = self.left_child.to_dict()
        return repr

    def to_list(self):
        lc = self.left_child.to_list() if self.left_child else []
        rc = self.right_child.to_list() if self.right_child else []
        return lc + [self.value] + rc

    @staticmethod
    def from_list(array):
        alen = len(array)
        middle = alen//2
        lc = array[:middle]
        val = array[middle]
        rc = array[middle+1:]
        root = BinTree(val)
        if lc:
            root.left_child = root.from_list(lc)
        if rc:
            root.right_child = root.from_list(rc)
        return root
