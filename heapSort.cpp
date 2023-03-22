#include<vector>
#include<iostream>
using namespace std;

bool adjustHeap(vector<int>& vec, int i, int length){
    int leftSon = (i + 1)* 2 - 1;
    int rightSon = (i + 1) * 2;
    int largeIndex  = i;
    if(leftSon < length && vec[largeIndex] < vec[leftSon]){
        largeIndex = leftSon;
    }

    if(rightSon < length && vec[largeIndex] < vec[rightSon]){
        largeIndex = rightSon;
    }

    if(largeIndex != i){
        swap(vec[i], vec[largeIndex]);
        adjustHeap(vec, largeIndex, length);
    }

    return true;
}
bool buildHeap(vector<int>& vec){
    int end = vec.size() / 2 - 1;
    for(int i = end; i >= 0; --i){
        adjustHeap(vec, i, vec.size());
    }
    return true;
}

//大根堆
bool heapSort(vector<int>& vec){
    buildHeap(vec);
    for(int i = vec.size() - 1; i >= 0; --i){
        swap(vec[i], vec[0]);
        adjustHeap(vec, 0, i);
    }
    return true;
}

int main(int argc, char** argv)
{
	vector<int> vec = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };

	heapSort(vec);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;

	return 0;
}