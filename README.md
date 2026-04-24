*This project has been created as part of the 42 curriculum by nbaudoin.*

# philosopher_42

- [philosopher\_42](#philosopher_42)
- [Description](#description)
	- [context](#context)
	- [Global Rules](#global-rules)
		- [Specific rules for manda](#specific-rules-for-manda)
- [Instructions](#instructions)
- [Resources](#resources)
		- [External function :](#external-function-)
	- [Sources](#sources)
	- [Use of AI](#use-of-ai)


# Description

- Learn the basics of threading a process.
- Learn how to create threads and explore the use of mutexes

## context

- One or more philo sit at a round table, there is a large bowl of spaghetti in the middle of the table
- The philo take turns :
  - eating : While eating, They are not thinking or sleeping
  - thinking : While thinking, they are not eating nor sleeping
  - sleeping : While sleeping, they are not eating nor thinking
- There are forks on the table, as many as philosophers
- Since eating spaghetti with 1 fork is impractical
  - A philo must pick up both the fork to their right and left before eating
- When a philo as finished eating, they put forks back on table and start sleeping
- Once awake, they start thinking again.
- The simulation stop when a philo dies of starvation.
- Every philo needs to eat and should never starve.
- Philo doesn't communicate with others
- Philo don't know if another is about to die
- Philo should avoid dying

## Global Rules

- **NO GLOBAL VARIABLE**
- take the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep[number_of_times_each_philosopher_must_eat]
```
- Args (time in milliseconds):
  - **number_of_philosophers** : number of **philo** and number of **forks**
  - **time_to_die** : if a philo doesn't eat before the end of this timer, it dies
  - **time_to_eat** : Time it takes to eat, need 2 forks
  - **time_to_sleep** : Sleeping time spent
  - **number_of_times_each_philosopher_must_eat (optional argument)**: If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
- Each philo has a number ranging from 1 to number of philo
- Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher, numbered N, sits between philosopher N - 1 and philosopher N + 1.

**About the logs of your program:**
Any state change of a philosopher must be formatted as follows:
  - timestamp_in_ms X has taken a fork
  - timestamp_in_ms X is eating
  - timestamp_in_ms X is sleeping
  - timestamp_in_ms X is thinking
  - timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
  - A displayed state message should not overlap with another message.
  - A message announcing a philosopher’s death must be displayed within 10 ms of
their actual death.


### Specific rules for manda

- Each philosopher must be represented as a separate thread.
- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, they will have access to just one fork.
- To prevent philosophers from duplicating forks, you should protect each fork’s state
with a mutex.



# Instructions

# Resources

### External function :

- [memset](https://koor.fr/C/cstring/memset.wp)
- [printf](https://koor.fr/C/cstdio/fprintf.wp)
- malloc
- free
- write
- [fork](https://man7.org/linux/man-pages/man2/fork.2.html)
- kill
- exit
- [pthread_create](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [pthread_detach](http://manpagesfr.free.fr/man/man3/pthread_detach.3.html)
- [pthread_join](http://manpagesfr.free.fr/man/man3/pthread_join.3.html)
- usleep
- gettimeofday
- waitpid
- [sem_open](http://manpagesfr.free.fr/man/man3/sem_open.3.html)
- [sem_close](http://manpagesfr.free.fr/man/man3/sem_close.3.html)
- [sem_post](https://man7.org/linux/man-pages/man3/sem_post.3.html)
- [sem_wait](http://manpagesfr.free.fr/man/man3/sem_wait.3.html)
- [sem_unlink](https://man7.org/linux/man-pages/man3/sem_unlink.3.html)

## Sources

## Use of AI

