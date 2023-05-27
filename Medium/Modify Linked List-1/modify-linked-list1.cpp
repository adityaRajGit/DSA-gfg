//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        if( head->next == NULL)
            return head;
            
       Node* slow = head , *fast = head , *prev1 = NULL;
       
       while(fast and fast->next)
       {
           prev1 = slow;
           slow = slow->next;
           fast = fast->next->next;
       }
       

     // first part ko ek seprate linked list bna liya (av ke liye)
       prev1->next = NULL;
       

      // second part ko reverse kr rhe
       Node* curr = slow , *prev = NULL;
       
       while(curr)
       {
           Node* next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
       }
       

      // first and second part ko traverse krke first part me  difference and second part me first part ke node ki value rakh rhe

       Node* curr1 = head , *curr2 = prev;
       
       while(curr1)
       {
           int temp = curr1->data;
           curr1->data = (curr2->data - curr1->data);
           curr2->data = temp;
           
           curr1 = curr1->next;
           curr2 = curr2->next;
       }
       

     // Ab again second part ko reverse kr rhe
       Node* curr3 = prev , *prev2 = NULL;
       
       while(curr3)
       {
           Node* next = curr3->next;
           curr3->next = prev2;
           prev2 = curr3;
           curr3 = next;
       }
       

    // first part se attach kr rhe


       prev1->next = prev2;
       
       return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends