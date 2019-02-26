#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &data, int start, int mid, int end) {
    vector<int> tmp;
    int i = start, j = mid + 1;
    while (i != mid + 1 && j != end + 1)
    {
        if (data[i] <= data[j])
        {
            tmp.push_back(data[i++]);
        }
        else
        {
            tmp.push_back(data[j++]);
        }
    }
    while (i != mid + 1)
    {
        tmp.push_back(data[i++]);
    }
    while (j != end + 1)
    {
        tmp.push_back(data[j++]);
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        data[start + i] = tmp[i];
    }
}



void merge_sort(vector<int> &data, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}


void output_array(vector<int> &data)
{
    for(auto i : data)
    {
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    int _data[] = {2, 4, 6, 0, 9, 8};
    vector<int> data(_data, _data + 6);
    merge_sort(data, 0, (int)data.size()-1);
    output_array(data);
    return 0;
}
