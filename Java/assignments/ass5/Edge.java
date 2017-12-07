public class Edge { 
    
    // global variables
    private Node u;
    private Node v;
    private String type;

    //main constructor
    public Edge(Node u, Node v, String type) {
        this.u = u;
        this.v = v;
        this.type = type;
    }

    //getter and setter methods
    public Node firstEndpoint() {
        return u;
    }

    public Node secondEndpoint() {
        return v;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}

