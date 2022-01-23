#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// commmand interpreter for commands without options & arguments
int main()
{
    char cmd[32];
    int i = 0;

    while (1)
    {
        write(1, ">", 1);
        while ((read(0, &cmd[i], 1)) && cmd[i] != '\n')
        {
            if (cmd[i] == ' ')
            {
                continue;
            }
            else
            {
                ++i;
            }
        }

        if (cmd[i] == '\n')
        {
            cmd[i] = '\0';
        }

        if (strcmp(cmd, "quit") == 0)
        {
            exit(0);
        }
        else
        {
            if (fork())
            {
                wait();
                i = 0;
            }
            else
            {
                if (execlp(cmd, cmd, 0) < 0)
                {
                    printf("Cannot execute %s\n", cmd);
                    exit(1);
                }
            }
        }
    }
    return 0;
}