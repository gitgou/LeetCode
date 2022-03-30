#include<iostream>
#include<string>
#include<vector>

using namespace std;
    
    void findAmendmentNo(string & version, vector<int>& vecAmendment)
    {
        string sAmendment;  
        while(version.size())
        {
            size_t pos = version.find('.');
            if(pos != string::npos)
            {
                sAmendment = version.substr(0, pos);
                version = version.substr(pos + 1);
                vecAmendment.push_back(atoi(sAmendment.c_str()));
                //cout << vecAmendment[vecAmendment.size() - 1] << endl;
            }
            else
            {
                vecAmendment.push_back(atoi(version.c_str()));
                version = "";
                //cout << vecAmendment[vecAmendment.size() - 1] << endl;

            }
        }
    }

    int compareVersion(string version1, string version2) 
    {
        vector<int> vec1;
        vector<int> vec2;
        findAmendmentNo(version1, vec1);
        findAmendmentNo(version2, vec2);
        int i = 0;
        for(; i < vec1.size() && i < vec2.size(); ++i)
        {
            if(vec1[i] < vec2[i])
            {
                return -1;
            }
            if(vec1[i] > vec2[i])
            {
                return 1;
            }
        }
        while (i < vec1.size())
        {
            if(vec1[i] != 0)
            {
                return 1;
            }
            ++i;
        }
        while (i < vec2.size())
        {
            if(vec2[i] != 0)
            {
                return -1;
            }
            ++i;
        }

        return 0;
    }

int main()
{ 
    cout << compareVersion("1.01", "1.001.1") << endl;;
    return 0;
}