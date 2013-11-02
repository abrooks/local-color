#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/stat.h>

typedef ssize_t (*fType)(int fd, void *buf, size_t count);
ssize_t (*their_read)(int fd, void *buf, size_t count) = NULL;

ssize_t read(int fd, void *buf, size_t count)
{
  if(! their_read) {
    void* handle = dlopen("libSystem.dylib", RTLD_NOW);
    their_read = (fType)dlsym(handle, "read");
  }

  size_t r = their_read(fd, buf, count);
  char * loc;
  struct stat sout, sfd;
  // Can cache the answers
  fstat(fileno(stdin), &sout);
  fstat(fd, &sfd);
  if((sout.st_dev==sfd.st_dev)
     && (sout.st_ino==sfd.st_ino)) {
    char * bp = (char *) buf;
    dprintf(fileno(stdout),"(COUNT:%d)>>%*s<<\n",(unsigned int)r,(unsigned int)r, bp);
    /*
    if ((loc = strnstr(bp, "\033", count))) {
      dprintf(fileno(stdout), ">>found %d %d<<\n", (int)*loc, ((bp+count) > loc)?(int)*(loc+1):-1);
      //bcopy(bar, loc, strlen(bar));
      //bp = loc + strlen(bar);
    }
    */
  }
  return r;
}
