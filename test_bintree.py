from unittest import TestCase, main
from bintree import BinTree


class TestInitializing(TestCase):
    def test_initialing_empty(self):
        b = BinTree()
        self.assertEqual(None, b.value)
        self.assertIsNone(b.right_child)
        self.assertIsNone(b.left_child)

    def test_initializing_value(self):
        b = BinTree(1)
        self.assertEqual(1, b.value)
        self.assertIsNone(b.right_child)
        self.assertIsNone(b.left_child)


class TestInserting(TestCase):
    def test_insertion_right(self):
            """
                3
                 \
                  4
            """
        b = BinTree(3)
        b.insert(4)
        self.assertIsInstance(b.right_child, BinTree)
        self.assertIsNone(b.left_child)

    def test_insertion_left(self):
        """
                3
               /
              2
        """
        b = BinTree(3)
        b.insert(2)
        self.assertIsInstance(b.left_child, BinTree)
        self.assertIsNone(b.right_child)


class TestRemoving(TestCase):
    def setUp(self):
        self.b = BinTree(3)
        self.b.insert_many(2, 5, 4, 6)

    def test_removing_root(self):
        """
                3
              /   \
            2       5
                   / \
                  4   6
            =>
                4
              /   \
            2       5
                      \
                        6
        """
        self.b.remove(3)
        self.assertEqual(4, self.b.value)
        self.assertIsNone(self.b.right_child.left_child)
        self.assertEqual(self.b.to_list(), [2, 4, 5, 6])

    def test_removing_child(self):
        """
                3
              /   \
            2       5
                   / \
                  4   6
            =>
                3
              /   \
            2       4
                      \
                        6
        """
        self.b.remove(5)
        self.assertEqual(self.b.right_child.value, 4)
        self.assertEqual(self.b.to_list(), [2, 3, 4, 6])

    def test_removing_leaf(self):
        """
                3
              /   \
            2       5
                   / \
                  4   6
            =>
                3
              /   \
            2       5
                   /
                  4
            =>
                3
              /   \
            2       5
        """
        self.b.remove(6)
        self.assertEqual(self.b.to_list(), [2, 3, 4, 5])
        self.b.remove(4)
        self.assertEqual(self.b.depth(), 2)

    def test_removing_non_branched_child(self):
        """
                6
                 \
                  10
                  /
                 8
                  \
                   9
            =>
                6
                 \
                  9
                 /
                8
        """
        b = BinTree(6)
        b.insert_many(10, 8, 9)
        b.remove(10)
        self.assertEqual(b.right_child.value, 9)
        self.assertEqual(b.to_list(), [6, 8, 9])
        self.assertEqual(b.depth(), 3)


if __name__ == "__main__":
    main()
