public class BinarySearchTree implements BinarySearchTreeADT {

    //variable declarations
    private BinaryNode root;

    //main constructor
    public BinarySearchTree() {
        root = new BinaryNode();
    }
    //get method
    public Pixel get(BinaryNode r, Location key) {
        Location temp;

        if (r.isLeaf()){
            return null;
        }
        //compares Location keys to find Pixel data
        temp = r.getData().getLocation();
        if (temp.compareTo(key) == 0) {
            return r.getData();
        }

        else if (key.compareTo(temp) < 0) {
            return get(r.getLeft(), key);
        }
        else {
            return get(r.getRight(), key);
        }
    }
    //put mthod
    public void put(BinaryNode r, Pixel data) throws DuplicatedKeyException {
        Location dataLocation, rLocation;

        //if empty tree
        if (r.isLeaf() == true) {
            r.setData(data);
            r.setLeft(new BinaryNode());
            r.getLeft().setParent(r);
            r.setRight(new BinaryNode());
            r.getRight().setParent(r);
        }
        else {
            //find where to place item
            dataLocation = data.getLocation();
            rLocation = r.getData().getLocation(); 

            if (dataLocation.compareTo(rLocation) == 0) {
                throw new DuplicatedKeyException("Duplicated Key");
            }

            else if ( dataLocation.compareTo(rLocation) < 0) {
                put(r.getLeft(), data);
            }

            else {
                put( r.getRight(), data);
            }
        }
    }
    //remove method
    public void remove(BinaryNode r, Location key) throws InexistentKeyException {
        BinaryNode temp = find(r, key);
        //Key does not exist
        if (temp == null || temp.isLeaf() == true) {
            throw new InexistentKeyException("Inexistent Key");
        }
        //Key is in tree and only has a left child
        else if(temp.getLeft() == null && temp.getRight() != null) {
            temp.getRight().setParent(temp.getParent());
        }
        //Key is in tree and only has a right child
        else  if(temp.getLeft() != null && temp.getRight() == null) {
            temp.getLeft().setParent(temp.getParent());

        }
        //Key is in tree and has two children
        else {
            //find succesor to node
            //set successor as replacement node
            if(successor(temp.getRight(), key) != null) {
                Pixel it = successor(temp.getRight(), key);
                BinaryNode v = find(r, it.getLocation());
                v.setLeft(temp.getLeft());
                v.setRight(temp.getRight());
                v.setParent(temp.getParent());
                temp = null;

            }                
        }
    }

    public Pixel successor(BinaryNode r, Location key) {
        //empty tree
        if (r.isLeaf() == true) {
            return null;
        }

        BinaryNode temp = find(r, key);
        //Key is in tree
        if (temp != null) {

            if (temp.getRight() == null || temp.isLeaf() == true) {
                return null;
            }
            else {
                BinaryNode it = suc(temp.getRight());
                return it.getData();
            }
        }
        //key is not in tree
        else {

            if(r.getRight() == null) {
                return null;
            }
            else {
                BinaryNode it = r;
                Pixel comp = it.getData();
                while (comp.getLocation().compareTo(key) < 0) {
                    it = it.getRight();
                }
                return suc(it).getData();
            }
        }
    }

    public Pixel predecessor(BinaryNode r, Location key) {
        //if tree is empty
        if (r.isLeaf() == true) {
            return null;
        }

        BinaryNode temp = find(r,key);
        //if key is in tree
        if (temp != null) {
            if(temp.getLeft() == null || temp.isLeaf() == true) {
                return null;
            }

            else {
                BinaryNode it = pre(temp.getLeft()); 
                return it.getData();
            }

        }
        //key is not in tree, find closest key
        else{

            if (r.getLeft() == null) {
                return null;
            }
            else {
                BinaryNode it = r;
                Pixel comp = it.getData();
                while (comp.getLocation().compareTo(key) > 0) {
                    it = it.getLeft(); 
                }
                return pre(it).getData();
            }
        }
    }
    //smallest method
    public Pixel smallest(BinaryNode r) throws EmptyTreeException {
        if (r.isLeaf() == true) {
            throw new EmptyTreeException("Empty");
        }

        else {
            BinaryNode temp = r;
            while (temp.isLeaf() == false) {
                temp = temp.getLeft();
            }

            return temp.getParent().getData();
        }
    }



    public Pixel largest(BinaryNode r) throws EmptyTreeException {
        if (r.isLeaf() == true) {
            throw new EmptyTreeException("Empty");
        }

        else {
            BinaryNode temp = r;
            while(temp.isLeaf() == false) {
                temp = temp.getRight();
            }

            return temp.getParent().getData();
        }
    }



    public BinaryNode getRoot() {
        return root;
    }

    private BinaryNode find(BinaryNode r, Location key){
        Location temp = r.getData().getLocation();

        if(r.isLeaf() == true) {
            return r;
        }

        else if (key.compareTo(temp) == 0) {
            return r;
        }
        else if ( key.compareTo(temp) < 0) {
            return find(r.getLeft(), key);
        }
        else {
            return find(r.getRight(), key);
        }
    }
    //successor helper function, finds smallest item recursively
    private BinaryNode suc(BinaryNode r) {
        BinaryNode temp = r;
        if (temp == null) {
            return null;
        }
        else if (temp.getLeft() == null) {
            return temp;
        }
        else {
            return suc(temp.getLeft());
        }
    }
    //predecessor helpr function, finds largest item recursively
    private BinaryNode pre(BinaryNode r) {
        BinaryNode temp = r;
        if (temp == null) {
            return null;
        }

        else if (temp.getRight() == null) {
            return temp;
        }
        else {
            return pre(temp.getRight());
        }
    }



}



