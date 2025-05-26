#include "shell.h"

t_builtin builtins[] = {
    {"echo", cell_echo},
    {"env", cell_env},
    {"exit", cell_exit},
    {"cd", cell_cd},  
    {NULL, NULL}      
};

int execute_builtin(char **args) {
    if (!args || !args[0]) return 1;
    
    for (int i = 0; builtins[i].builtin_name; i++) {
        if (strcmp(args[0], builtins[i].builtin_name) == 0) {
            return builtins[i].foo(args);
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    (void)argc; (void)argv;
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    printbanner();
    
    while (1) {
        printf(Y "cell_jr> " RST);
        fflush(stdout);
        
        read = getline(&line, &len, stdin);
        if (read == -1) break;
        
        char *args[100] = {NULL};
        char *token = strtok(line, " \n");
        int i = 0;
        
        while (token && i < 99) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        
        if (i > 0) {
            if (execute_builtin(args)) {
                pid_t pid = Fork();
                if (pid == 0) {
                    Execvp(args[0], args);
                } else {
                    Wait(NULL);
                }
            }
        }
        
        free(line);
        line = NULL;
    }
    
    if (line) free(line);
    return EX_OK;
}