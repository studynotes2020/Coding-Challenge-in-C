/* mutex comes in two varieties
*
* one is a "non-recursive" mutex - the most primitive mutex
*
* a non-recursive mutex can only be locked once by any thread
*
* if you have threads A & B, then each can only try locking the mutex once.
* If thread A holds the mutex already, it cannot try locking it again
*
* another type of mutex is a "recursive" mutex.
*
* with a recursive mutex, if thread A holds the mutex already, it can lock it
* again
*/

/* have these already */
typedef struct mutex_nr mutex_nr_t;

void mutex_lock_nr(mutex_nr_t *m);
void mutex_unlock_nr(mutex_nr_t *m);

int get_current_thread_id();

/* please write */

/* data structure definitions */

#define INVALID_THREAD_ID -1

struct mutex_recursive {
  int cnt;
  mutex_nr_t m;
  int current_thread_id;

};

typedef struct mutex_recursive mutex_recursive_t;

/* functions */
void mutex_lock_recursive(mutex_recursive_t *m) {
  if (m->current_thread_id == get_current_thread_id()) {
    m->cnt++;
  } else {

    mutex_lock_nr(&m->m);
    m->cnt = 1;
    m->current_thread_id = get_current_thread_id();
  }
}

void mutex_unlock_recursive(mutex_recursive_t *m) {
  if (m->current_thread_id == get_current_thread_id()) {
    m->cnt--;
    if (m->cnt == 0) {
      m->current_thread_id = INVALID_THREAD_ID;
      mutex_unlock_nr(&m->m);
    }
  } else {
    /* should not be called */
  }
}