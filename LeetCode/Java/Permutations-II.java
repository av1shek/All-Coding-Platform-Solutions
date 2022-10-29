class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results=new ArrayList<>();
        HashMap<Integer,Integer> counter=new HashMap<>();
        for(int num: nums){
            if(!counter.containsKey(num))
                counter.put(num,0);
            counter.put(num,counter.get(num)+1);
        }
        LinkedList<Integer> comb=new LinkedList<>();
        backtrack(comb,nums.length,counter,results);
        return results;
    }
    void backtrack(LinkedList<Integer> comb,int N, HashMap<Integer,Integer> counter,List<List<Integer>> results){
        if(comb.size()==N){
            results.add(new ArrayList<Integer> (comb));
            return;
        }
        for(Map.Entry<Integer,Integer> entry: counter.entrySet()){
            Integer num=entry.getKey();
            Integer count=entry.getValue();
            if(count==0)
                continue;
            comb.addLast(num);
            counter.put(num,count-1);
            backtrack(comb,N,counter,results);
            comb.removeLast();
            counter.put(num,count);
        }
    }

}