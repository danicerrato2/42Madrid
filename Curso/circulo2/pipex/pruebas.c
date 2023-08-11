#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void exec_child1(char **envp)
{
    char *args[] = {"/bin/sleep", "9", 0};
    char *cmd = "/bin/sleep";

    execve(cmd, args, envp);
}

void exec_child2(char **envp)
{
    char *args[] = {"/bin/sleep", "4", 0};
    char *cmd = "/bin/sleep";

    execve(cmd, args, envp);
}

int main(int argc, char **argv, char **envp)
{
    int child1;
    int child2;

    child1 = fork();
    if (child1 == -1){
        printf("Creacion del hijo fallida\n");
        return (1);
    }
    if (child1 == 0)
    {
        exec_child1(envp);
        return (0);
    }
    child2 = fork();
    if (child2 == -1){
        printf("Creacion del hijo fallida\n");
        return (1);
    }
    if (child2 == 0)
    {
        exec_child2(envp);
        return (0);
    }
    waitpid(child2, 0, 0);
    waitpid(child1, 0, 0);
    return (0);
}