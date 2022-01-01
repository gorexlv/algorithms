/*
Package heap is the implementation of Binary Heap which is going to help us
implement all the priority queue quickly.

So the idea of a binary heap is based on the idea of a complete binary tree.
Now the way we're going to use a complete binary trees to implement priority
queues is to first of all associate information with each node. We'll put our
keys in the nodes. And also we're going to represent it with an array.

So when we start putting the keys in the nodes, we're going to impose one more
condition that's called heap ordering. And the idea is that the parent's key
is going to be no smaller than its children's key, and that's true for every
node in the tree. For easy calculation , we start with indices at 1.
The way that we move around the tree is by doing arithmetic on the
indices.
	- Parent of node at k is at k/2.
	- Children of node at k is at 2k and 2k+1.

The largest key is a[1], which is root of binary tree. The time complexity of
both insertion and deletion priority key happens in log N time. It is
recommanded to use immutable keys.
*/
package heap
