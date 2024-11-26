#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid = fork();

    switch (pid)
    {
    case -1:
        perror("fork faild!");
        return 1;
    case 0:
        printf("Child process, pid: \t%d! tgid: \t%d! tid:\t%d!\n", getpid(), getpgid(0), gettid());
        break;
    default:
        printf("Parent process, pid: \t%d, tgid: \t%d! tid: \t%d!\n", getpid(), getpgid(0), gettid());
        wait(nullptr);

        printf("Child process finished!\n");
        break;
    }

    return 0;
}
