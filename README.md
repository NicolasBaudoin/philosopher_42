*This project has been created as part of the 42 curriculum by nbaudoin.*
<a id="#top"></a>

# **Philosopher**

- [**Philosopher**](#philosopher)
	- [**Description**](#description)
		- [Context](#context)
		- [Global Rules](#global-rules)
		- [Specific rules for mandatory](#specific-rules-for-mandatory)
	- [**Instructions**](#instructions)
		- [Getting the project and compilation](#getting-the-project-and-compilation)
		- [Usage](#usage)
	- [**Resources**](#resources)
		- [External functions](#external-functions)
		- [Sources](#sources)
		- [Use of AI](#use-of-ai)
## **Description**

**Philosopher** is a project to introduce the use of **threads** and **mutexes**.
The classic **Dining Philosophers Problem** illustrates the challenges of **concurrent programming** — how to manage shared resources between multiple threads without causing **deadlocks** or **starvation**.

Each philosopher is represented as a **thread**. Each fork is a **mutex** that can only be held by one philosopher at a time. The simulation runs until a philosopher dies or all philosophers have eaten enough.

### Context

- One or more philosophers sit at a round table, there is a large bowl of spaghetti in the middle
- Philosophers take turns doing three things:
  - **eating** : needs two forks (left and right), cannot think or sleep
  - **sleeping** : cannot eat or think
  - **thinking** : cannot eat or sleep
- There are as many forks as philosophers
- When a philosopher finishes eating, they put forks back and start sleeping
- Once awake, they start thinking again
- The simulation stops when a philosopher dies of starvation
- Philosophers don't communicate with each other
- Philosophers don't know if another is about to die
### Global Rules

- **NO GLOBAL VARIABLES**
- Takes the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- Arguments (time in milliseconds):
  - **number_of_philosophers** : number of philosophers and number of forks
  - **time_to_die** : if a philosopher doesn't start eating within this time since their last meal or the start of the simulation, they die
  - **time_to_eat** : time it takes to eat, philosopher must hold two forks
  - **time_to_sleep** : time spent sleeping
  - **number_of_times_each_philosopher_must_eat** *(optional)* : if all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
- Each philosopher has a number from 1 to number_of_philosophers
- Philosopher 1 sits next to philosopher number_of_philosophers
- Any philosopher N sits between philosopher N-1 and philosopher N+1
**Log format — any state change must follow this format:**
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
- Messages must not overlap with each other
- A death message must be displayed within 10ms of the actual death
### Specific rules for mandatory

- Each philosopher must be a separate **thread**
- One fork between each pair of philosophers — protected by a **mutex**
- If there is only one philosopher, they only have one fork
[**back to top**](#top)

## **Instructions**

### Getting the project and compilation

**1. Clone the repository**

```bash
git clone [vogsphere_link] [custom_name]
```

**2. Enter the directory**

```bash
cd [directory_name]/philo
```

**3. Compile using the Makefile:**

```bash
make
```

This will generate the executable: `philo`

[**back to top**](#top)

### Usage

**Run the simulation with arguments:**

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Examples:**

```bash
# 1 philosopher — will die (only one fork available)
./philo 1 800 200 200

# 5 philosophers — no one should die
./philo 5 800 200 200

# 4 philosophers — tight timing, no one should die
./philo 4 410 200 200

# 4 philosophers — someone should die
./philo 4 310 200 100

# 5 philosophers — stops after 7 meals each
./philo 5 800 200 200 7
```

**Expected output:**

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
100 1 is sleeping
100 3 has taken a fork
100 3 is eating
...
801 2 died
```

[**back to top**](#top)

## **Resources**

### External functions

- [pthread_create](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [pthread_detach](http://manpagesfr.free.fr/man/man3/pthread_detach.3.html)
- [pthread_join](http://manpagesfr.free.fr/man/man3/pthread_join.3.html)
- [pthread_mutex_init](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html)
- [pthread_mutex_lock / unlock / destroy](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
- [usleep](https://man7.org/linux/man-pages/man3/usleep.3.html)

### Sources
- [What is a mutex - CodeVault](https://www.youtube.com/watch?v=oq29KUy29iQ)
- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Dining Philosophers — Coding overflow (YouTube)](https://www.youtube.com/watch?v=o_GbRujGCnM)
- [Playlist Philosophers 42 - 15 videos of usefull thing for philosopher — CodeVault (YouTube)](https://www.youtube.com/watch?v=kCGaRdArSnA&list=PLGU1kcPKHMKi41Py2kqxdvqYE3M9VhCHe)
- [pthread man pages](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
- [concurrency-stress-tester — 42PhilosophersHelper](https://github.com/AbdallahZerfaoui/concurrency-stress-tester)
### Use of AI

- Help understand the difference between `static`, `sig_atomic_t`, `_Atomic` and `pthread_mutex` for thread safety
- Explain deadlock scenarios and the even/odd fork-taking strategy
- Review struct design and forward declaration for circular dependencies
- Help debug data races on `time_last_meal` and `dead` flag. had wrong approach with is_dead.
- Review `free_all` cleanup order (destroy before free) and understand how to "free" / destroy mutex
- Explain `pthread_detach` vs `pthread_join`

[**back to top**](#top)
