#include<iostream>
#include<vector>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[],
    int wt[], int at[])
{
    vector<int> service_time(3);
    service_time[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < 3; i++)
    {
        service_time[i] = service_time[i - 1] + bt[i - 1];

        wt[i] = service_time[i] - at[i];

        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[],
    int wt[], int tat[])
{
    for (int i = 0; i < 3; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[3], tat[3];

    findWaitingTime(processes, 3, bt, wt, at);

    findTurnAroundTime(processes, 3, bt, wt, tat);

    cout << "Processes " << " Burst Time " << " Arrival Time "
        << " Waiting Time " << " Turn-Around Time "
        << " Completion Time \n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < 3; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t\t"
            << at[i] << "\t\t" << wt[i] << "\t\t "
            << tat[i] << "\t\t " << compl_time << endl;
    }

    cout << "Average waiting time = "
        << (float)total_wt / (float)3;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)3;
}

int main()
{
    int n = 3;
    int processes[] = { 1, 2, 3 };
    
    int burst_time[] = { 4, 8, 5 };

    int arrival_time[] = { 0, 2, 5 };

    findavgTime(processes, 3, burst_time, arrival_time);

    return 0;
}