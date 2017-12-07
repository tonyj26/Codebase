import java.util.*;

public class Graph implements GraphADT {

    //global variables
    //two hashmaps are used to simulate a bidirectional map
    private HashMap<Node,ArrayList<Edge>> adj;
    private HashMap<Integer, Node> nodeList;
    //initalizes a graph size n, with no edges
    public Graph(int n) {

        //initializes the hashmaps and fills the nodelist with nodes from 0 to n-1
        adj = new HashMap<Node, ArrayList<Edge>>();
        nodeList = new HashMap<Integer, Node>();
        for (int i = 0; i < n; i++) {
            Node temp = new Node(i);
            adj.put(temp, new ArrayList<Edge>());
            nodeList.put(i, temp);
        }
    }

    //inserts an edge into the graph
    public void insertEdge(Node u, Node v, String edgeType) throws GraphException {
        //try clause to catch exceptions
        try 
        {
            //if node does not exist
            if(!nodeList.containsValue(u) || !nodeList.containsValue(v)) {
                throw new GraphException("Node does not exist");
            }


            //this is to ensure that ordering of the endpoints does not matter
            Edge temp  = new Edge(u, v, edgeType);
            Edge reverse = new Edge(v, u, edgeType);

            ArrayList<Edge> list = adj.get(u);

            //if the adjacency list contains the edge than throw an exception
            if(list.contains(temp) || list.contains(reverse)) {
                throw new GraphException("Edge already exists");
            }
            else {
                //adds the edge to the adjaceny list of both nodes
                adj.get(u).add(temp);
                adj.get(v).add(temp);
            }
        }
        catch (GraphException e) {
            throw e;
        }
    }

    //returns the node with the parameter name
    public Node getNode(int name) throws GraphException {
        if (!nodeList.containsKey(name)) {
            
            throw new GraphException("Node does not exist");
        }

        else {
            return nodeList.get(name);
        }
    }

    //returns an iterator object 
    public Iterator<Edge> incidentEdges(Node u) throws GraphException {
        try
        {
            //ensures that the node is in the graph
            Node temp = getNode(u.getName());

            //if no edges are in the list
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

            //checks if the edge is in the adjacency list 
            //this block ensures that ordering of endpoints does not matter
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

            //returns true if there is an edge between the nodes
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
