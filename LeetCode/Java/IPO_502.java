import java.util.PriorityQueue;

class T
{
    int cap,pro;
    T(int c,int p)
    {
        cap=c;
        pro=p;
    }
}
class IPO_502 {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        boolean allSmall=true;
        for(int x:capital)
        {
            if(x>w)
            { allSmall=false;
            break;}
        }
        if (allSmall) {
            PriorityQueue<Integer> profit = new PriorityQueue<>((x, y) -> (x - y));
            for (int i : profits) {
                profit.add(i);
                if (profit.size() > k) {
                    profit.poll();
                }
            }
            while (profit.size() > 0) {
                w += profit.poll();
            }    
            return w;
        }
            PriorityQueue<T> minCapital=new PriorityQueue<>((a,b)->a.cap-b.cap);
        PriorityQueue<T> maxProfit=new PriorityQueue<>((a,b)->b.pro-a.pro);
        for(int i=0;i<profits.length;i++)
        {
            minCapital.offer(new T(capital[i],profits[i]));
        }
        while(k>0)
        {
            while(minCapital.isEmpty()==false&&minCapital.peek().cap<=w)
            {
                maxProfit.offer(minCapital.poll());
            }
            if(maxProfit.isEmpty())
                break;
             w += maxProfit.poll().pro;
            k--;
        }
        return w;
        
    }
}