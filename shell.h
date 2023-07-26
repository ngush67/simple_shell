#ifndef SHELL
#define SHELL

#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */
list_t *add_end_node(list_t **head, char *str);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
int built_in(char **token, list_t *env, int num, char **command);
void cant_cd_to(char *str, int c_n, list_t *env);
int _cd(char **str, list_t *env, int num);
char **c_str_tok(char *str, char *delm);
int _env(char **str, list_t *env);
list_t *env_linked_list(char **env);
int _execve(char *argv[], list_t *env, int num);
int __exit(char **s, list_t *env, int num, char **command);
int delete_nodeint_at_index(list_t **head, int index);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
int find_env(list_t *env, char *str);
char *get_env(char *str, list_t *env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *ignore_space(char *str);
void illegal_number(char *str, int c_n, list_t *env);
char *int_to_string(int num);
void non_interactive(list_t *env);
void not_found(char *str, int num, list_t *env);
size_t print_list(list_t *h);
int prompt(char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _setenv(list_t **env, char **str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int t_strlen(char *str, int pos, char delm);
char **_str_tok(char *str, char *delm);
int _unsetenv(list_t **env, char **str);
char *_which(char *str, list_t *env);


#endif
