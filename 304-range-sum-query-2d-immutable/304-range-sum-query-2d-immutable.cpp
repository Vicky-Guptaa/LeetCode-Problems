class NumMatrix
{
    public:
        vector<vector < int>> preSumX;
    NumMatrix(vector<vector < int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> temp(cols + 1, 0);
        preSumX.push_back(temp);
        for (int i = 0; i < rows; i++)
        {
            int sum = 0;
            vector<int> row = { 0 };
            for (int j = 0; j < cols; j++)
            {
                sum += matrix[i][j];
                row.push_back(sum);
            }
            preSumX.push_back(row);
        }

        for (int i = 0; i <= cols; i++)
        {
            int sum = 0;
            for (int j = 0; j <= rows; j++)
            {
                sum += preSumX[j][i];
                preSumX[j][i] = sum;
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = preSumX[row2+1][col2+1] - preSumX[row1][col2+1] + preSumX[row1][col1] - preSumX[row2+1][col1];

        return ans;
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */