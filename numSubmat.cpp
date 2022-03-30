#include<iostream>
#include<vector>

using namespace std;

    int numSubmat(vector<vector<int> >& mat) {
        int width1, width2, heigh1, heigh2 = -1;
        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 1 && width1 == -1)
                {
                    width1 = width2 = j;
                }
            }
        }
    }

int main()
{
    return 0;
}