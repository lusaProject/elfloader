#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void *worker(void *arg)
    {
        printf("------hello world!--------\n");
    }

    void main1(void)
    {
        int i;
        pthread_t th[10];

        for (i = 0; i < 10; ++i)
            pthread_create(&th[i], NULL, worker, NULL);

        sleep(1);
    }

#ifdef __cplusplus
}
#endif
