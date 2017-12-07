import java.util.*;
import java.io.*;
import java.lang.Thread;

public class Labyrinth {
    //initializing global variables
    private Graph g = null;
    private Node start;
    private Node end;
    private int bBombs;
    private int aBombs;
    private int size;

    public Labyrinth(String inputFile) throws LabyrinthException {
        //throws an exception if the inputfile does not exist
        if (inputFile == null) {
            throw new LabyrinthException("Invalid input");
        }
        //initializing instance variables;
        BufferedReader input;
        String line;
        char lab[][];
        int i, col, row = 0;
        try {
            //creates a new buffer reader from inputfile
            input = new BufferedReader(new FileReader(inputFile));

            //parses first 5 lines of the input file 
            int roomsize = Integer.parseInt(input.readLine());
            int width = Integer.parseInt(input.readLine());
            int length = Integer.parseInt(input.readLine());
            bBombs = Integer.parseInt(input.readLine());
            aBombs = Integer.parseInt(input.readLine());
            size = width*length;

            //creates a new graph
            g = new Graph(size);
            //creates a multidimensional character array to insert edges
            lab = new char[2*length-1][2*width-1];
            for(;;) {
                line = input.readLine();
                if (line == null) {
                    input.close();
                    return;
                }

                //reads characters from the input file and adds the appropiate edges to the graph
                for (i = 0, col = 0; i < line.length(); ++i) {
                    lab[row][i] = line.charAt(i);
                    switch(line.charAt(i)) {
                        case 'b': start = g.getNode((width * row) + i);
                                  ++col; break;
                        case 'x': end = g.getNode((width * row) + i);
                                  ++col; break;
                        case 'h': g.insertEdge(g.getNode((width * row) + i -1), 
                                          g.getNode((width * row) + i + 1), "wall");
                                  ++col; break;
                        case 'v': g.insertEdge(g.getNode((width * (row -1)) + i), 
                                          g.getNode((width * (row+1)) + i), "wall");
                                  ++col; break;
                        case 'H': g.insertEdge(g.getNode((width * row) + i -1), 
                                          g.getNode((width * row) + i + 1), "thickWall");
                                  ++col; break;
                        case 'V': g.insertEdge(g.getNode((width * (row -1)) + i), 
                                          g.getNode((width * (row+1)) + i), "thickWall");
                                  ++col; break;                      
                        case 'm': g.insertEdge(g.getNode((width * row) + i -1), 
                                          g.getNode((width * row) + i + 1), "metalWall");
                                  ++col; break;
                        case 'M': g.insertEdge(g.getNode((width * (row -1)) + i), 
                                          g.getNode((width * (row+1)) + i), "metalWall");
                                  ++col; break;
                        case '-': g.insertEdge(g.getNode((width * row) + i -1), 
                                          g.getNode((width * row) + i + 1), "hall");
                                  ++col; break;
                        case '|': g.insertEdge(g.getNode((width * (row -1)) + i), 
                                          g.getNode((width * (row+1)) + i), "hall");
                                  ++col; break;
                        case '+': ++col;
                    }
                    ++row;
                }
            }
        }

        //catches any exceptions
        catch(IOException e) {
            System.out.println("error");
        }
        catch (Exception e) {
            System.out.println("Error opening file");
        }
    }


    //returns a refernce to the Graph, null if graph not defined
    public Graph getGraph() throws LabyrinthException {
        if (g == null) {
            throw new LabyrinthException("Graph not defined");
        }

        return g;
    }
    
    //marks all nodes as unmarked, then uses a depth first search to solve the labyrinth
    public Iterator solve() {
        setUnmarked();
        Iterator iter = pathDFS(g, start, end).iterator();
        return iter;
    }

    //sets all nodes in the graph to unmarked
    private void setUnmarked() {
        try {
            //Ensure the graph is defined
            Graph temp = getGraph();

            for (int i = 0; i < size; i++) {
                temp.getNode(i).setMark(false);
            }
        }
        catch(LabyrinthException e) {
            System.out.println("Exception: " + e);
        }
        catch(GraphException e) {
            System.out.println("Exception: " + e);
        }
    }

    private Stack<Node> pathDFS(Graph g, Node u, Node v) {
        try {

            //initializes variables
            Stack<Node> S = new Stack<Node>();
            Stack<Node> result = new Stack<Node>();
            //push current node onto stack
            S.push(u);
            //path found, return it
            if (u == v) {
                return S;
            }
            //while there exists incident edges, check if the next node is unmarked, then recursively visit it
            while (g.incidentEdges(u).hasNext()) {
                Edge nextEdge = g.incidentEdges(u).next();
                if(nextEdge.firstEndpoint() != u && nextEdge.firstEndpoint().getMark() == false) {
                   result = pathDFS(g, nextEdge.firstEndpoint(), v);
                   //if a path is found return it 
                    if (result != null) {
                        return result;
                    }
                }

                else if (nextEdge.secondEndpoint() != u && nextEdge.firstEndpoint().getMark() == false) {
                   result = pathDFS(g, nextEdge.secondEndpoint(), v);
                    if (result != null) {
                        return result;
                    }
                }
            }
            S.pop();
            return null;
        }
        catch(GraphException e) {
            System.out.println("Exception: " + e);
        }
        return null;
    }
}

