

class Solution
{
    void countLeaves(Node root, ArrayList<Integer> v, int k, int[] ans) {
        // Leaf Node reached
        if (root.left == null && root.right == null) {
            int index = v.size() - k;
            if (index >= 0 && index < v.size()) {
                ans[0] += v.get(index);
                v.set(index, 0);
            } else if (k == 0) {
                ans[0]++;
            }
            return;
        }
        v.add(1);
        if (root.left != null) {
            countLeaves(root.left, v, k, ans);
        }
        if (root.right != null) {
            countLeaves(root.right, v, k, ans);
        }
        v.remove(v.size() - 1);
    }

    int printKDistantfromLeaf(Node root, int k) {
        int[] ans = { 0 };
        ArrayList<Integer> v = new ArrayList<>();
        countLeaves(root, v, k, ans);
        return ans[0];
    }
}
