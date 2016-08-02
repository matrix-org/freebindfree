#define _GNU_SOURCE

#include <dlfcn.h>
#include <netinet/in.h>

static int (*next_socket)(int domain, int type, int protocol);

int socket(int domain, int type, int protocol)
{
  if(!next_socket) {
    next_socket = dlsym(RTLD_NEXT, "socket");
  }

  int fd = (*next_socket)(domain, type, protocol);
  if(fd < 0)
    return fd;

  int one = 1;
  setsockopt(fd, SOL_IP, IP_FREEBIND, &one, sizeof(one));

  return fd;
}
