import java.util.*;

public class MyDigraph<Vertex> {
    /**
     * We put the vertices of the graph into the map
     * every vertex is key the values of the vertex is the other vertex which they are adjacent.
     */
    private Map<Vertex, List<Vertex>> graph = new HashMap<Vertex,List<Vertex>>();
    private boolean isVisited =false;
    LinkedList<Integer> adj;

    /**
     * 1 -> [3,4]
     * 2 ->[1,3]
     * 3 ->[]
     * 4 ->[3]
     * the output looks like this.
     */
    @Override
    public String toString() {
       StringBuffer s = new StringBuffer();
        for (Vertex vertex: graph.keySet()) {
            s.append("\n  " + vertex +  " -> " + graph.get(vertex));
        }
        return s.toString();
    }

    /**
     * we add  vertex into the map as a key
     * if vertex is already exists it just pass.
     */
    public void add(Vertex vertex){
        if (graph.containsKey(vertex)) return;
        graph.put(vertex,new ArrayList<>());
    }

    /**
     * return the whether the vertex in to the graph or not.
     */
    public boolean contains(Vertex vertex){
        return graph.containsKey(vertex);
    }

    /**
     *it adds an edge between from and to.
     * but first it adds from and to into the graph if they are not exist.
     */

    public void add (Vertex from ,Vertex to){
        this.add(from);
        this.add(to);
        graph.get(from).add(to);
    }

    /**
     * remove the edge between from and to if exist.
     */
    public void remove (Vertex from,Vertex to){
        if(!(this.contains(from)&&this.contains(to))){
            throw new IllegalArgumentException("Vertex doesn't exist.");
        }
        graph.get(from).remove(to);

    }

    /**
     *return a map which contains out degree of each vertex.
     */
    public Map outDegree(){
       Map<Vertex,Integer> outDeg = new HashMap<>();
        for(Vertex v:graph.keySet()){
            outDeg.put(v,graph.get(v).size());
        }

       return outDeg;
    }
    /**
     *return a map which contains indegree of each vertex.
     */
    public Map inDegree(){
        Map<Vertex,Integer> inDeg = new HashMap<>();
        for(Vertex v:graph.keySet()){
            inDeg.put(v,0);
        }
        for(Vertex from:graph.keySet()){ // from to mantığını iyi kavraman gerekiyor.
            for(Vertex to :graph.get(from)){
                inDeg.put(to,inDeg.get(to)+1);
            }
        }


        return inDeg;
    }

    /**
     * it didnt run because of the `java.util.ConcurrentModificationException`
     */
   /* public boolean isDag(){
        Map<Vertex,Integer> inDegree= inDegree();
        int i =0;
        for(Vertex v:inDegree.keySet()){
            if (inDegree.get(v).equals(0)){
                for(Vertex from:graph.keySet()){ // from to mantığını iyi kavraman gerekiyor.
                    for(Vertex to :graph.get(from)){
                        this.remove(from,to);
                    }
                }
            }
            i++;
        }
        return graph.isEmpty();
    }*/

   public List<Vertex> topSort(){
      Map<Vertex,Integer> degree = inDegree();
      Stack<Vertex> vertexStack = new Stack<>();
      for(Vertex v : degree.keySet()){
          if (degree.get(v) == 0){
              vertexStack.push(v);
          }
      }
      List<Vertex> topSort = new ArrayList<>();
      while (!vertexStack.isEmpty()){
          Vertex v = vertexStack.pop();
          topSort.add(v);
          for(Vertex neighbour : graph.keySet()){
              degree.put(neighbour,degree.get(neighbour)-1);

              if (degree.get(neighbour) == 0) vertexStack.push(neighbour);
          }
      }
      if (topSort.size()!=graph.size()) return null;
      return topSort;
   }
   public boolean isDag(){
       Map<Vertex,Integer> degree = inDegree();
       Stack<Vertex> vertexStack = new Stack<>();
       for(Vertex v : degree.keySet()){
           if (degree.get(v) == 0){
               vertexStack.push(v);
           }
       }
       List<Vertex> topSort = new ArrayList<>();
       while (!vertexStack.isEmpty()){
           Vertex v = vertexStack.pop();
           topSort.add(v);
           for(Vertex neighbour : graph.keySet()){
               degree.put(neighbour,degree.get(neighbour)-1);

               if (degree.get(neighbour) == 0) vertexStack.push(neighbour);
           }
       }
       if (topSort.size()!=graph.size()) return false;
       return true;
   }

   public Map bfsDistance(Vertex start){
       Map<Vertex,Integer> distance = new HashMap<>();
       for (Vertex v : graph.keySet()){
           distance.put(v,null);
       }
       distance.put(start,0);
       Queue<Vertex> vertexQueue = new LinkedList<>();
       vertexQueue.offer(start);
       while (!vertexQueue.isEmpty()) {
           Vertex v = vertexQueue.remove();
           int vDist = distance.get(v);
           for (Vertex neighbour:graph.get(v)){
               if (distance.get(neighbour)!=null) continue;
               distance.put(neighbour,vDist+1);
               vertexQueue.offer(neighbour);
           }
       }
       return distance;
   }
   public void DFS(){
       int vertices = graph.size();
       boolean [] visited = new boolean[vertices];

       for (Vertex v : graph.keySet()){

       }

   }
    public static void main(String[] args) {
        MyDigraph graph= new MyDigraph();
        graph.add(0, 1); graph.add(0, 2); graph.add(0, 3);
        graph.add(1, 2); graph.add(1, 3); graph.add(2, 3);
        graph.add(2, 4); graph.add(4, 5); graph.add(5, 6);



    }



























}
