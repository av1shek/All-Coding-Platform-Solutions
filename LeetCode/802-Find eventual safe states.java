class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        
        boolean [] visited=new boolean[graph.length];
        boolean [] dfsvisited=new boolean[graph.length];
        
        HashSet<Integer> hp=new HashSet<>();
        
        for(int i =0;i<graph.length;i++){
            if(visited[i]==false){
            if(isCyclic(i,graph,visited,dfsvisited,hp)){

            }
            }
        }
            
        List<Integer> ans=new ArrayList<>();
        for(int i =0;i<graph.length;i++){
            if(hp.contains(i)==true){
                ans.add(i);
            }
        }
        return ans;
    }
    
    public static boolean isCyclic(int node,int[][] graph,boolean [] visited,boolean [] dfsvisited,HashSet<Integer> hp){
        visited[node]=true;
        dfsvisited[node]=true;
        
        for(int nbrs:graph[node]){
            if(visited[nbrs]==false){
                if(isCyclic(nbrs,graph,visited,dfsvisited,hp)){
                    return true;
                }
            }
            else if(dfsvisited[nbrs]==true){
                    return true;
                }
            }
            hp.add(node);
        dfsvisited[node]=false;
        return false;
        }
    
}