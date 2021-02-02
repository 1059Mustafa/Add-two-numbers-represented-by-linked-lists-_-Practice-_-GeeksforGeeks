Node* reverse(Node* head)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* addition(Node* first, Node* second)
{
        
        
        int sum=0;
        int carry=0;
        Node* start=NULL;
        Node* end=NULL;
        while(first!=NULL||second!=NULL)
        {
            sum=carry+(first?first->data:0)+(second?second->data:0);
            carry=(sum>=10?1:0);
            sum=sum%10;
            if(start==NULL)
            {
                start=new Node(sum);
                end=start;
            }
            else
            {
                end->next=new Node(sum);
                end=end->next;
            }
            if(first!=NULL)
            {
                first=first->next;
            }
            if(second!=NULL)
            {
                second=second->next;
            }
            
        }
        if(carry>0)
        {
            end->next=new Node(carry);
        }
        start=reverse(start);
        return start;
    
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    struct Node* ans;
    first=reverse(first);
    second=reverse(second);
    ans=addition(first,second);
    
    return ans;
}

