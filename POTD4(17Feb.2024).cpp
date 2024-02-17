class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int l) {
        /*///Bricks finishing approach
        if(l>=heights.size()){
            return heights.size()-1;
        }
        int n=heights.size();
        int i=0;
        while(i<n-1)
        {

          if(heights[i+1]>heights[i])
          { int diff=heights[i+1]-heights[i];
            if(diff<=bricks){
                bricks=bricks-diff;
            }
            else{
                if(l!=0){
                    l--;
                }
                else
                {
                       return i;
                }
            }
            i++;  
          }
          else
              i++;
          
        }
        return i;*/

        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>>heap;
        int i=0;
        while(i<n-1){
            if(heights[i+1]>heights[i])
            {  int diff=heights[i+1]-heights[i];
               heap.push(diff);
               if(heap.size()>l)
               {
                   bricks-=heap.top();
                   heap.pop();
               }
               if(bricks<0){
                   return i;
               }
               i++;
            }
            else
               i++;

        }
        return i;
    }
};
