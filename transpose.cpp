#include<vector>
#include<iostream>

using namespace std;

    vector<vector<int> > transpose(vector<vector<int> >& matrix) {
        if(matrix.size() == 0)
        {return vector<vector<int> >();}

        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > res(col, vector<int> (row));
        cout << res.size() << ", " << res[0].size() << endl;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }

int main()
{
    return 0;
}