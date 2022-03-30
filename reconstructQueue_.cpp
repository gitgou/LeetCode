#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 
    //Compare 返回布尔值, 递增判断left < right == true
    struct Compare
    {
        bool operator() (vector<int>& left, vector<int>& right)
        {
            //如果第一个数相等，使用第二个数判断， 排序成一个递增序列--从低到高
            return left[0] < right[0] || (left[0] == right[0] && left[1] < right[1]);
        }
    };

    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) 
    {
        sort(people.begin(), people.end(), Compare());
        //people.insert()
        //开始插入从后开始插入，也可以从前往后遍历
        for(int i = people.size() - 1; i >= 0; --i)
        {
            vector<int> person = people[i];
            //找出前面有几个比他大的数
            int forward = i - 1, large = 0;
            while(forward >= 0 && person[0] == people[forward][0])
            {
                --forward;
                ++large;
            }
            //cout << forward << endl;
            //通过移动来插入，
            int j = i + 1;
            for(; j < people.size() && j <= (i + person[1] - large); ++j)
            {
                people[j - 1] = people[j];
            }
            people[j - 1] = person;

            for(int k = 0; k < people.size(); ++k)
            {
                cout << people[k][0] << ", " << people[k][1] << "; ";
            }
            cout << endl;

            
        }

        return people;
    }

int main()
{
    vector<vector<int> > vec{{4,4}, {7, 1}, {5, 2}, {5, 0}, {7, 0}, {6,1}};
    vector<vector<int> > result = reconstructQueue(vec);
    return 0; 
}