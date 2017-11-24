public class GraphicalObject implements GraphicalObjectADT {
    
    // variable declarations
    private BinarySearchTree tree;
    private int id;
    private int width;
    private int height;
    private String type;
    private Location pos;
    
    //main constructor
    public GraphicalObject(int id, int width, int height, String type, Location pos) {
        tree = new BinarySearchTree();
        this.id = id;
        this.width = width;
        this.height = height;
        this.type = type;
        this.pos = pos;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public String getType() {
        return type;
    }

    public int getId() {
        return id;
    }

    public Location getOffset() {
        return pos;
    }

    public void setOffset(Location value) {
       this.pos = value;
    }

    public void addPixel(Pixel pix) throws DuplicatedKeyException {
        
        tree.put(tree.getRoot(), pix);
    }

    public boolean intersects(GraphicalObject gobj) {
        //declaring variables
        Location temp = gobj.getOffset();
        int x1 = pos.xCoord();
        int x2 = temp.xCoord();
        int y1 = pos.yCoord();
        int y2 = temp.yCoord();

        //checking for overlap
        if (x1 <= x2) {
            if (x2 > x1 + width) {
                return false;
            }
        }
        else if ( y1 > y2 + gobj.getHeight()) {
            return false;
        }

        Pixel pix;
        Location a, b;
        
        
        try {
            pix = tree.smallest(tree.getRoot());
            while (pix != null) {
                a = pix.getLocation();
                b = new Location(a.xCoord() + x1 - x2, a.yCoord() + y1 - y2);
                if (gobj.findPixel(b) != null) {
                    return true;
                }
                else {
                    pix = tree.successor(tree.getRoot(), a);
                }
            }
        }
            catch (EmptyTreeException e) {
                System.out.println("Empty");
            }
            return false;
        }


    private Pixel findPixel(Location p) {
        return tree.get(tree.getRoot(), p);
    }
}
