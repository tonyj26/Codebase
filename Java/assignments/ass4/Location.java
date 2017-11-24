public class Location {
    int x;
    int y;

    public Location(int x,int y) {
        this.x = x;
        this.y = y;
    }

    public int xCoord() {
        return x;
    }

    public int yCoord() {
        return y;
    }

    public int compareTo(Location p) {
        if ((x> p.xCoord()) || (xCoord() == p.xCoord() && y > p.yCoord())){
            return 1;
        }
        else if ( x == p.xCoord() && y == p.yCoord()) {
            return 0;
        }
        return -1;
    }

}


