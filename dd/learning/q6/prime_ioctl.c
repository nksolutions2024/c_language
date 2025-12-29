#ifndef PRIME_IOCTL_H
#define PRIME_IOCTL_H

#include <linux/ioctl.h>

#define PRIME_IOCTL_MAGIC 'p'

#define SEND_NUMBER _IOW(PRIME_IOCTL_MAGIC, 1, int)
#define GET_PRIMES  _IOR(PRIME_IOCTL_MAGIC, 2, int *)

#endif

