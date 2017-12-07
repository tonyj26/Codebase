import java.util.*;

public class Node {

    //initializes global variables
    private int name;
    private boolean mark;

    //main constructor
    public Node(int name) {
        this.name = name;
    }

    //setter method to set the node as visited or not
    public void setMark(boolean mark) {
        this.mark = mark;
    }

    //getter method to check mark status
    public boolean getMark() {
        return mark;
    }

    // returns name of node
    public int getName() {
        return name;
    }
}

