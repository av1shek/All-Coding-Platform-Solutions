import java.util.HashSet;

public class ValidSudoku_36 {
    
        public boolean isValidSudoku(char[][] s) 
        {
             int n=s.length;
        int i;
        HashSet<Character>[] rows=new HashSet[n];
        HashSet<Character>[] col=new HashSet[n];
        HashSet<Character>[] box=new HashSet[n];
        for ( i = 0; i < n; i++) {
            rows[i] = new HashSet<Character>();
            col[i] = new HashSet<Character>();
            box[i] = new HashSet<Character>();
        }
        for( i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char val=s[i][j];
                if(val=='.')
                continue;
                if(rows[i].contains(val))
                return false;
                rows[i].add(val);
                if(col[j].contains(val))
                return false;
                col[j].add(val);
                int idx=i/3*3+j/3;
                //System.out.println(idx+" "+i+" "+j);
                if(box[idx].contains(val))
                {
                    return false;
                }
                box[idx].add(val);
    
    
            }
    
        }
        return true;
        }
    }

