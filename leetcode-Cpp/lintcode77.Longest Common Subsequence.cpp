class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        int m[lenA+1][lenB+1];
        memset(m, 0, sizeof(m));
        for(int i=1; i<=lenA; i++)
        {
            for(int j=1; j<=lenB; j++)
            {
                if(A[i-1]==B[j-1])
                    m[i][j] = m[i-1][j-1]+1;
                else 
                    m[i][j] = max(m[i-1][j], m[i][j-1]);
            }
        }
        int result = m[lenA][lenB];

        return result;
    }
};
