#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int num = 100;
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        _exit(-1);
    }

    if (pid == 0)
    {
        /* 子进程 */
        printf("child process :num:%d\n", num);

        num += 100;
        printf("child process :num:%d\n", num);

        /* 将num写到文件 */
        int fd = open("./needRead.txt", O_RDWR|O_CREAT, 0644);
        if (fd == -1)
        {
            perror("open error");
        }
        /* 写数据 */
        write(fd, (void *)&num, sizeof(num));

        close(fd);


    }
    else if (pid > 0)
    {
        /* 父进程 */
        printf("parent process :num:%d\n", num);
        sleep(1);
        printf("parent process :num:%d\n", num);

        /* 从文件里面读出来 */
        int fd = open("./needRead.txt", O_RDWR);
        if (fd == -1)
        {
            perror("open error");
        }

        int readNum = 0;
        read(fd,(void*)&readNum, sizeof(int));
        close(fd);
        printf("parent process :readNum:%d\n", readNum);


    }
    wait(NULL);

    printf("hello world\n");

    return 0;
}