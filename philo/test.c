// philo_test.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_PHILOS 3

typedef struct s_philo
{
    int             id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}   t_philo;

pthread_mutex_t forks[NB_PHILOS];
pthread_mutex_t print_mutex;

void    print_status(t_philo *philo, char *status)
{
    pthread_mutex_lock(&print_mutex);
    printf("Philo %d %s\n", philo->id, status);
    pthread_mutex_unlock(&print_mutex);
}

void    *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        // penser
        print_status(philo, "is thinking");

        // prendre les fourchettes
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "took left fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "took right fork");

        // manger
        print_status(philo, "is eating");
        usleep(200000); // 200ms

        // poser les fourchettes
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        // dormir
        print_status(philo, "is sleeping");
        usleep(200000);
    }
    return (NULL);
}

int main(void)
{
    pthread_t   tids[NB_PHILOS];
    t_philo     philos[NB_PHILOS];
    int         i;

    // Init mutex fourchettes
    i = 0;
    while (i < NB_PHILOS)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&print_mutex, NULL);

    // Init philos
    i = 0;
    while (i < NB_PHILOS)
    {
        philos[i].id = i + 1;
        philos[i].left_fork = &forks[i];
        philos[i].right_fork = &forks[(i + 1) % NB_PHILOS];
        i++;
    }

    // Lancer les threads
    i = 0;
    while (i < NB_PHILOS)
    {
        pthread_create(&tids[i], NULL, routine, &philos[i]);
        i++;
    }

    // Attendre (infini ici)
    i = 0;
    while (i < NB_PHILOS)
    {
        pthread_join(tids[i], NULL);
        i++;
    }
    return (0);
}