#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct DSA
{
    int req_id;
    int arr_time;
    int cyl;
    int addr;
    int p_id;
};

void FCFS(struct DSA *req, int n_req)
{
    int curr_cyl = 0;
    int tot_mvmt = 0;

    printf("FCFS Disk Scheduling:\n");
    for (int i = 0; i < n_req; i++)
    {
        tot_mvmt += abs(curr_cyl - req[i].cyl);
        printf("P%d -> C%d\n", req[i].p_id, req[i].cyl);
        curr_cyl = req[i].cyl;
    }

    printf("Total head movement: %d\n", tot_mvmt);
}

void SSTF(struct DSA *req, int n_req)
{
    int curr_cyl = 0;
    int tot_mvmt = 0;

    printf("SSTF Disk Scheduling:\n");
    while (n_req > 0)
    {
        int min_seek = INT_MAX;
        int min_i = -1;

        for (int i = 0; i < n_req; i++)
        {
            int seek_time = abs(curr_cyl - req[i].cyl);
            if (seek_time < min_seek)
            {
                min_seek = seek_time;
                min_i = i;
            }
        }

        struct DSA close_req = req[min_i];
        tot_mvmt += min_seek;
        printf("P%d -> C%d\n", close_req.p_id, close_req.cyl);
        curr_cyl = close_req.cyl;

        for (int i = min_i; i < n_req - 1; i++)
        {
            req[i] = req[i + 1];
        }

        n_req--;
    }

    printf("Total head movement: %d\n", tot_mvmt);
}

int main()
{
    struct DSA req[] = {
        {1, 0, 50, 0, 1},
        {2, 0, 100, 0, 2},
        {3, 0, 25, 0, 3},
        {4, 0, 75, 0, 4},
        {5, 0, 125, 0, 5}};
    int n_req = 5;

    FCFS(req, n_req);
    printf("\n");

    SSTF(req, n_req);

    return 0;
}
