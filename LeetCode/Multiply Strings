class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' or num2[0]=='0')
            return "0";
        char z[100005];
        string s;
        memset(z,'0',sizeof(z));
        int c=0,k=0,q=0;
        for(int i=num1.size()-1;i>=0;i--)
        {
            c=0;
            int p=k;
            for(int j=num2.size()-1;j>=0;j--)
            {
                int d=(num1[i]-'0')*(num2[j]-'0')+c;
                if(d>9)
                {
                    c=d/10;
                    d%=10;
                }
                else
                    c=0;
                int l=(z[p]-'0')+d;
                if(l>9)
                {
                    z[p]=(l%10)+'0';
                    c+=l/10;
                }
                else
                    z[p]=(l%10)+'0';
                p++;
            }
            if(c>0)
            {
                z[p]=(z[p]-'0'+c)+'0';
                p++;
            }
            k++;
            q=max(q,p);
            // for(int i1=0;i1<q;i1++)
            //     cout<<z[i1];
            // cout<<endl;
        }
        // cout<<"k="<<k<<endl;
        for(int i=q-1;i>=0;i--)
            s+=z[i];
        // cout<<endl;
        return s;
    }
};

