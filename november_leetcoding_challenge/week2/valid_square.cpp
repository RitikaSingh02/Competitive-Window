class Solution {
public:
    long long int distance(vector<int> a, vector<int> b )
    {
        return pow((a[0] - b[0]),2)+pow((a[1] - b[1]),2); 
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        long long int d2 = distance(p1, p2); // from p1 to p2 
        long long int d3 = distance(p1, p3); // from p1 to p3 
        long long int d4 = distance(p1, p4); // from p1 to p4 
        if(d2==0||d3==0||d4==0)
            return false;   
        
        cout<<d2 <<" "<<d3<<" "<<d4;
        if (d2 == d3 && 2 * d2 == d4 
            && 2 * distance(p2, p4) == distance(p2, p3) )  
        {       
            int dist = distance(p2, p4);
            return (dist == distance(p3, p4) && dist == d2);
        }
        if (d3 == d4 && 2 * d3 == d2 
            && 2 * distance(p3, p2) == distance(p3, p4) ) 
        {cout<<"y1";
            int dist = distance(p2, p3);
            return (dist == distance(p2, p4) && dist == d3);
        }
        if (d2 == d4 && 2 * d2 == d3 
            && 2 * distance(p2, p3) == distance(p2, p4)) 
        {
            int dist = distance(p2, p3);
        return (dist == distance(p3, p4) && dist == d2);
        }
        
  
    return false; 
     
    
    }
};