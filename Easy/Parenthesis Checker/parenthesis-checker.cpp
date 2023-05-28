//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool bordercheck(char a,char b)
    {
        if((a=='[' && b == ']') ||(a=='{' && b == '}')||(a=='(' && b == ')')){
            return true;
        }
        return false;
    }
    
    bool ispar(string x)
    {
        int n = x.length();
        
        // all changes will be applied to this variable
        string word=x;
        
        for(int i=0;i<n-1;i++){
            
            // cheking the consecutive letters, checking (i,i+1)th index and (i-1,i)th index
            if( bordercheck(word[i],word[i+1])||bordercheck(word[i-1],word[i])){
                
                //removing the pairs from the word
                word.erase(i,2);
                
                //reducing the i value to match with the vaccent space created after the removal of pairs
                i-=2;    
            }
        }
        //The loop will run untill it's "i" reaches "n-1",
        //After the above loop is completed we will be having the unpaired sample,
        //Checking the word is empty or not 
        if(word.empty()){
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends