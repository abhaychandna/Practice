#include<iostream>
#include<set>
#include<unordered_set>
#include<queue>

using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;

    queue<int> indexes;

    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);

                page_faults++;

                indexes.push(pages[i]);
            }
        }

        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();

                indexes.pop();

                s.erase(val);

                s.insert(pages[i]);

                indexes.push(pages[i]);

                page_faults++;
            }
        }
    }

    return page_faults;
}

int main()
{
    int pages[] = { 1,3,0,3,5,6,3 };
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    cout << "No of page faults - " << pageFaults(pages, n, capacity);
    return 0;
}