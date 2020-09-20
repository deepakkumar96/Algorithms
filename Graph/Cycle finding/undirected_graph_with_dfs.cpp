import java.util.*;

class Graph {
    private final Map<Integer, List<Integer>> adj;
    private final Set<Integer> vertices;

    Graph() {
        adj = new HashMap<>();
        vertices = new HashSet<>();
    }

    private List<Integer> newVal() {
        return new LinkedList<>();
    }
    private void addEdge_(int u, int v) {
        List<Integer> list = adj.getOrDefault(u, newVal());
        list.add(v);
        adj.putIfAbsent(u, list);
    }
    public void addEdge(int u, int v) {
        addEdge_(u, v);
        addEdge_(v, u);
        vertices.add(u);
        vertices.add(v);
    }

    public List<Integer> getAdj(int v) {
        return adj.getOrDefault(v, newVal());
    }

    public Set<Integer> getVertices() {
        return vertices;
    }
}

public class CycleInUndirectedGraph {

    public static void main(String[] args) {
        Graph g = new Graph();
        g.addEdge(1, 3);
        g.addEdge(3, 4);
        g.addEdge(3, 5);
        g.addEdge(5, 6);
        g.addEdge(3, 6);

        Set<Integer> vis = new HashSet<>();
        boolean hasCycle = false;
        for (int v: g.getVertices()) {
            if (!vis.contains(v)) {
                if (dfs(g, vis,  v, -1)) {
                    hasCycle = true;
                }
            }
        }
        System.out.println(hasCycle? "Cycle found": "No cycle found");
    }


    public static boolean dfs(Graph g, Set<Integer> vis, int v, int p) {
        if (vis.contains(v)) {
            return false;
        }
        vis.add(v);
        System.out.println(v);
        for (int y: g.getAdj(v)) {
            if (!vis.contains(y)) {
                if (dfs(g, vis, y, v)) {
                    return true;
                }
            } else if (y != p) {
                /*
                    This means there is a back-edge v to y, y is adjacent to v but not a parent of v
                 */
                return true;
            }
        }
        return false;
    }
}
