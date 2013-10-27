#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

typedef ssize_t (*fType)(int fildes, const void *buf, size_t nbyte);
ssize_t (*their_write)(int fildes, const void *buf, size_t nbyte) = NULL;

ssize_t write(int fildes, const void *buf, size_t nbyte)
{
  if(! their_write) {
    void* handle = dlopen("libSystem.dylib", RTLD_NOW);
    their_write = (fType)dlsym(handle, "write");
  }

  const char *foo="\033[48;5;48m";
  const char *bar="\033[48;5;99m";
  char *loc = NULL;

  if( fildes == 1 ) {
    char * bp = (char *) buf;
    while ((loc = strnstr(bp, foo, nbyte))) {
      bcopy(bar, loc, strlen(bar));
      bp = loc + strlen(bar);
    }
  }
  return their_write(fildes, buf, nbyte);
}
