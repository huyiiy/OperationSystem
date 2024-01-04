#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main ()
{
#if 0
    int fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }
    
    char *ptr = "hello world";
    /* 向文件中写数据 */
    int bytes = write(fd, ptr, strlen(ptr) + 1);
    if (bytes < 0)
    {
        perror("write error");
    }
    else
    {
        printf("bytes:%d\n", bytes);
    }
    close(fd);

#endif

#if 0
    /* 打开文件 */
    /* */
    int fd = open("./hello.txt", O_RDWR | O_TRUNC);
    if (fd == -1)
    {
        perror("open error");
    }

    close(fd);

#endif


#if 1
    /* 打开文件 */
    /* 以追加的方式打开文件 */
    int fd = open("./hello.txt", O_RDWR | O_APPEND);
    if (fd == -1)
    {
        perror("open error");
    }

    char ptr[] = "123\n";

    write(fd, ptr, sizeof(ptr));
    close(fd);
#endif
    return 0;
}