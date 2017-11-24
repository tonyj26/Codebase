public class Pixel {
    
    Location p;
    int color;

    public Pixel(Location p, int color) {
        this.p = p;
        this.color = color;
    }

    public Location getLocation() {
        return p;
    }

    public int getColor() {
        return color;
    }
}


