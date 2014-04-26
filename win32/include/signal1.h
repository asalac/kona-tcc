#include <errno.h>
#include <signal.h>

#define SA_RESTART   0x10000000 	/* Restart syscall on signal return */
#define SA_NOCLDSTOP 1  /* only value supported now for sa_flags */

typedef unsigned long sigset_t;
typedef void (*_sig_func_ptr)(int);

struct sigaction {
  int         sa_flags;       /* Special flags to affect behavior of signal */
  sigset_t    sa_mask;        /* Additional set of signals to be blocked */
                              /*   during execution of signal-catching */
                              /*   function. */
  union {
    _sig_func_ptr _handler;  /* SIG_DFL, SIG_IGN, or pointer to a function */
  } _signal_handlers;
};

#define sa_handler    _signal_handlers._handler
#if defined(_POSIX_REALTIME_SIGNALS)
#define sa_sigaction  _signal_handlers._sigaction
#endif

/* If ACT is not NULL, change the action for SIG to *ACT.
   If OACT is not NULL, put the old action for SIG in *OACT.  */
int sigaction (sig, act, oact)
     int sig;
     const struct sigaction *act;
     struct sigaction *oact;
{
  if (sig <= 0 || sig >= NSIG)
    {
      errno= EINVAL;
      return -1;
    }

  errno=ENOSYS;
  return -1;
}
