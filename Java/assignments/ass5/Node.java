import java.util.*;

public class Node {

    private int name;
    private boolean mark;

    public Node(int name) {
        this.name = name;
    }

    public void setMark(boolean mark) {
        this.mark = mark;
    }

    public boolean getMark() {
        return mark;
    }

    public int getName() {
        return name;
    }
}

