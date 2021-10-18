typedef struct TreeNode *btptr;
class Solution {
public:
    bool isCousins(btptr T, int x, int y) {
        if(T==NULL)
            return false;
        queue<btptr> q;
        q.push(T);
        q.push(NULL);
        while(!q.empty())
        {
            btptr temp = q.front(); q.pop();
            if(temp == NULL && (!q.empty()) )
            {
                q.push(NULL);
                continue;
            }
               
            if(temp->val == x || temp->val==y)
            {
                if(q.front()==NULL)
                    return false;
                if(q.front()->val != 999999999)
                    q.pop();
                while(q.front()!=NULL && !q.empty())
                {
                    if(q.front()->val + temp->val == x+y )
                        return true;
                    q.pop();
                }
                return false;
            }
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            if(temp->left || temp->right)
            {
                btptr temp2 = new TreeNode(999999999);
                q.push(temp2);
            }
                
            
        }
        return false;
    }
};
