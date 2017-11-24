public class BinaryNode{

    private Pixel value;
    private BinaryNode left;
    private BinaryNode right;
    private BinaryNode parent;

    public BinaryNode(Pixel value, BinaryNode left, BinaryNode right, BinaryNode parent) {
        this.value = value;
        this.left = left;
        this.right = right;
        this.parent = parent;
    }    

    public BinaryNode() {
        this(null,null,null,null); 
    }

    public BinaryNode getParent() {
        return parent;
    }

    public void setParent(BinaryNode p) {
        parent = p;
    }

    public void setLeft(BinaryNode p) {
        left = p;
    }

    public void setRight(BinaryNode p) {
        right = p;
    }

    public void setData(Pixel value) {
        this.value = value;
    }

    public boolean isLeaf() {
        if ( left == null && right == null) {
            return true;
        }
        else {
            return false;
        }
    }

    public Pixel getData() {
        return value;
    }

    public BinaryNode getLeft() {
        return left;
    }

    public BinaryNode getRight() {
        return right;
    }
}




