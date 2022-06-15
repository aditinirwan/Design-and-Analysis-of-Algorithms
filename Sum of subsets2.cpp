/*Start with an empty set
Add the next element from the list to the set
If the subset is having sum M, then stop with that subset as solution.
If the subset is not feasible or if we have reached the end of the set, 
then backtrack through the subset until we find the most suitable value.
If the subset is feasible (sum of seubset < M) then go to step 2.
If we have visited all the elements without finding a suitable subset and 
if no backtracking is possible then stop without solution.*/

    /* Part of Cosmos by OpenGenus Foundation */
    #include<iostream>
    using namespace std;
    /*
    *Find whether or not there exists any subset 
    *  of array  that sum up to targetSum
    */
    class Subset_Sum
    {
        public:
        // BACKTRACKING ALGORITHM
        void subsetsum_Backtracking(int Set[] , int pos, int sum, int tmpsum, int size, bool & found)
        {
            if (sum == tmpsum)
                found = true;
                // generate nodes along the breadth
            for (int i = pos; i < size; i++)
            {
             if (tmpsum + Set[i] <= sum)
               {
                  tmpsum += Set[i];   
                  // consider next level node (along depth)
                  subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
                  
                  tmpsum -= Set[i];
                }
                cout<<Set[i]<<" ";
            }
        }
    };
    
    int main()
    {
        int i, n=8, sum=53;
        Subset_Sum S;
        int a[n]={15,22,14,26,32,9,16,8};
        bool f = false;
        S.subsetsum_Backtracking(a, 0, sum, 0, n, f);
        if (f)
           cout << "subset with the given sum found" << endl;
        else
           cout << "no required subset found" << endl;   
        return 0;
    }

