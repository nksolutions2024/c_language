#ifndef EMPLOYEE_IOCTL_H
#define EMPLOYEE_IOCTL_H

#include <linux/ioctl.h>

#define MAGIC 'E'

typedef struct {
    char name[10];
    int id;
    char gender;   // 'm' or 'f'
} employee_t;

#define SEND_EMPLOYEE_DATA _IOW(MAGIC, 1, employee_t)
#define GET_LIST_SIZE     _IOR(MAGIC, 2, int)
#define PRINT_LIST        _IO(MAGIC, 3)

#endif

