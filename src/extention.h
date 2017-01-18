#ifndef _EXTENTION_H_
#define _EXTENTION_H_

#include <arpa/inet.h>
#include <netinet/ip.h>

char *bind_addr = "0.0.0.0";

static int extention_bind(int fd) {
  struct sockaddr_in addr;

  setsockopt(SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

  addr.sin_family = AF_INET;
  addr.sin_port = 0;
  addr.sin_addr.s_addr = inet_addr(bind_addr);

  return bind(fd, (struct sockaddr *)&addr, sizeof(addr));
}

#endif /* _EXTENTION_H_ */
