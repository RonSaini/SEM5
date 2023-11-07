#include <stdio.h>
#include <pthread.h>

#define max_r 5
#define max_t 3

int avail[max_r];
int max[max_t][max_r];
int alloc[max_t][max_r];
pthread_mutex_t mutex;

int safe()
{
    int w[max_r], f[max_t] = {0};

    for (int i = 0; i < max_r; i++)
        w[i] = avail[i];

    int c = 0;
    while (c < max_t)
    {
        int found = 0;
        for (int i = 0; i < max_t; i++)
        {
            if (!f[i])
            {
                int j;
                for (j = 0; j < max_r; j++)
                {
                    if (max[i][j] - alloc[i][j] > w[j])
                        break;
                }
                if (j == max_r)
                {
                    for (int k = 0; k < max_r; k++)
                        w[k] += alloc[i][k];
                    f[i] = 1;
                    found = 1;
                    c++;
                }
            }
        }
        if (!found)
            return 0;
    }
    return 1;
}

void request(int thread_id, int req[])
{
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < max_r; i++)
    {
        if (req[i] > avail[i])
        {
            printf("Thread %d: Denied\n", thread_id);
            pthread_mutex_unlock(&mutex);
            return;
        }
    }

    for (int i = 0; i < max_r; i++)
    {
        avail[i] -= req[i];
        alloc[thread_id][i] += req[i];
    }

    if (safe())
        printf("Thread %d: Granted\n", thread_id);
    else
    {
        for (int i = 0; i < max_r; i++)
        {
            avail[i] += req[i];
            alloc[thread_id][i] -= req[i];
        }
        printf("Thread %d: Denied\n", thread_id);
    }

    pthread_mutex_unlock(&mutex);
}

void release(int thread_id, int rel[])
{
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < max_r; i++)
    {
        avail[i] += rel[i];
        alloc[thread_id][i] -= rel[i];
    }

    printf("Thread %d: Released.\n", thread_id);

    pthread_mutex_unlock(&mutex);
}

void *threadFunction(void *arg)
{
    int thread_id = *((int *)arg);

    int req[max_r] = {0, 0, 0, 0, 0};
    int rel[max_r] = {0, 0, 0, 0, 0};

    if (thread_id == 0)
    {
        req[0] = 2;
        request(thread_id, req);
        sleep(1);
        rel[0] = 2;
        release(thread_id, rel);
    }
    else if (thread_id == 1)
    {
        req[1] = 3;
        request(thread_id, req);
        sleep(1);
        rel[1] = 3;
        release(thread_id, rel);
    }
    else if (thread_id == 2)
    {
        req[2] = 1;
        request(thread_id, req);
        sleep(1);
        rel[2] = 1;
        release(thread_id, rel);
    }

    return NULL;
}

int main()
{
    for (int i = 0; i < max_r; i++)
        avail[i] = 10;

    pthread_t threads[max_t];
    int thread_ids[max_t];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < max_t; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, &thread_ids[i]);
    }

    for (int i = 0; i < max_t; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
