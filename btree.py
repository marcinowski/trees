class BTree(object):
    degree = 2

    def __init__(self, value=None):
        self.root = root

    def insert(self, value):
        raise NotImplemented

    def remove(self, value):
        raise NotImplemented

    def search(self, value):
        raise NotImplemented

    def validate(self):



class TreeGroup(object):
    def __init__(self, node):
        self.nodes = [node]

    def add_node(self, node):
        self.nodes.append(node)
        self.nodes.sort()


class TreeNode(object):
    def __init__(self, value):
        self.left_group = None
        self.right_group = None
        self.value = value

    @property
    def leaf(self):
        return not self.children
