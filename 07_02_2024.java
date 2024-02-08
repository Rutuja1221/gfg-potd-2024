

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
   Node(int item)    {
        data = item;
        left = right = null;
    }
} */

/* Should return minimum distance between a and b
   in a tree with given root*/
class GfG {
    // Function to find the Lowest Common Ancestor (LCA)
    private Node findLCA(Node root, int a, int b) {
        if (root == null || root.data == a || root.data == b) {
            return root;
        }

        Node leftLCA = findLCA(root.left, a, b);
        Node rightLCA = findLCA(root.right, a, b);

        if (leftLCA != null && rightLCA != null) {
            return root;
        }

        return (leftLCA != null) ? leftLCA : rightLCA;
    }

    // Function to calculate the distance from a node to another node
    private int findDistance(Node root, int target, int distance) {
        if (root == null) {
            return -1;
        }

        if (root.data == target) {
            return distance;
        }

        int leftDistance = findDistance(root.left, target, distance + 1);
        if (leftDistance != -1) {
            return leftDistance;
        }

        return findDistance(root.right, target, distance + 1);
    }

    // Function to find the minimum distance between nodes a and b
    int findDist(Node root, int a, int b) {
        // Find the Lowest Common Ancestor (LCA)
        Node lca = findLCA(root, a, b);

        // Calculate the distance from LCA to nodes a and b separately
        int distanceA = findDistance(lca, a, 0);
        int distanceB = findDistance(lca, b, 0);

        // Return the total distance
        return distanceA + distanceB;
    }
}