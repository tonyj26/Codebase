import java.util.*;

public class Graph implements GraphADT {

    private HashMap<Node,ArrayList<Edge>> adj;
    private HashMap<Integer, Node> nodeList;
    public Graph(int n) {

        adj = new HashMap<Node, ArrayList<Edge>>();
        nodeList = new HashMap<Integer, Node>();
        for (int i = 0; i < n; i++) {
            Node temp = new Node(i);
            adj.put(temp, new ArrayList<Edge>());
            nodeList.put(i, temp);
        }
    }

    public void insertEdge(Node u, Node v, String edgeType) throws GraphException {
        try 
        {
            if(!nodeList.containsValue(u) || !nodeList.containsValue(v)) {
                throw new GraphException("Node does not exist");
            }


            Edge temp  = new Edge(u, v, edgeType);
            Edge reverse = new Edge(v, u, edgeType);

            ArrayList<Edge> list = adj.get(u);

            if(list.contains(temp) || list.contains(reverse)) {
                throw new GraphException("Edge already exists");
            }
            else {
                adj.get(u).add(temp);
                adj.get(v).add(temp);
            }
        }
        catch (GraphException e) {
            throw e;
        }
    }

    public Node getNode(int name) throws GraphException {
        if (!nodeList.containsKey(name)) {
            
            throw new GraphException("Node does not exist");
        }

        else {
            return nodeList.get(name);
        }
    }

    public Iterator<Edge> incidentEdges(Node u) throws GraphException {
        try
        {
            Node temp = getNode(u.getName());

            ArrayList<Edge> it = adj.get(temp);
            if (it.isEmpty()) {
                return null;
            }

            else {
                return it.iterator();
            }
        }
        catch (GraphException e){
            throw e;
        }
    }

    public Edge getEdge(Node u, Node v) throws GraphException {
        Edge temp = null;
        try
        {

            Iterator<Edge> it = incidentEdges(u);
            if (it != null) {
                while (it.hasNext()){
                    temp = it.next();
                    if (temp.firstEndpoint() == u && temp.secondEndpoint() == v) {
                        return temp;
                    }
                    else if (temp.firstEndpoint() == v && temp.secondEndpoint() == u) {
                        return temp;
                    }
                }
            }
        } 
        catch (GraphException e) {
            throw e;
        }
        return temp;
    }

    public boolean areAdjacent(Node u, Node v) throws GraphException {
        try {

            Edge temp = getEdge(u, v); 
            if (temp != null) {
                return true;
            }
        }
        catch (GraphException e) {
            throw e;
        }
        return false;
    }
}
