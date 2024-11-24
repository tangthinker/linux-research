#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <linux/sched.h>

using namespace std;


int main(int argc, char const *argv[])
{

    int current_pid = getpid();

    cout << "current_pid: " << current_pid << endl;


    FILE *file;
    char buffer[256];
    char pid_path[32];

    snprintf(pid_path, sizeof(pid_path), "/proc/%d", current_pid);

    printf("current_pid_path: %s\n", pid_path);

     char status_path[64];
    snprintf(status_path, sizeof(status_path), "%s/status", pid_path);
    
    file = fopen(status_path, "r");
    if (file == NULL) {
        perror("无法打开文件");
        return EXIT_FAILURE;
    }

    // 读取并打印进程状态信息
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);


    

    return 0;
}
