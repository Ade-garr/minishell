/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:38:41 by user42            #+#    #+#             */
/*   Updated: 2021/03/29 10:32:17 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <termios.h>
# include <curses.h>
# include <term.h>


# define BUFFER_SIZE 50

//LIBFT
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

///GNL
int					ft_position(char *left);
int					ft_free(char **line);
int					ft_checkleft(char *left);
size_t				ft_strlen_gnl(const char *s);
char				*ft_join(char *line, char *left);
void				ft_moveleft(char *left, char *newleft);
int					ft_fill_line(int fd, char **line, char (*left)[BUFFER_SIZE + 1]);
int					ft_give_line(char **line, char *left);
int					get_next_line(int fd, char **line);

//MINISHELL

typedef struct		s_shell
{
	t_list			*env;
	t_list			*cmd;
	t_list			*tmp;
	t_list			*tmpdir;
	char			*line;
	pid_t			pid_pipe;
	pid_t			pid_exec;
	int				pipefd[2];
	int				flagparent; // à voir si à garder
	int				returnvalue; // à voir si à garder
	struct termios	orig_termios;
	int				flag_termios;
	char			*del_c;		//pas besoin de free
	char			*del_line;	//pas besoin de free, à voir si à garder ou non
	char			*left_c;	//pas besoin de free
	char			*line_up;	//pas besoin de free
	char			*end_line;
	int				nb_col;
	int				pos_x;
	int				nb_hist;
	t_list			*hist;
	char			*saved_line;
}					t_shell;

t_shell *g_shell;

typedef struct		s_cmdinfo
{
	int				flagpipe;
	char			**exec;
	t_list			*dir;
}					t_cmdinfo;

typedef struct		s_dirinfo
{
	int				flagdir;
	char			*file;
}					t_dirinfo;

	//main.c
void				get_list_env(char **env);
void				init_shell(void);
void				ft_exit(void);
void				ft_error(void);
int					main(int argc, char **argv, char **env);

	//execute.c
void				ft_exec_cmd(void);
void				ft_process_cmd(void);
void				ft_do_pipes(void);
void				ft_do_dup_child(void);
void				ft_do_dup_parent(void);

	//utils.c
void				ft_incr_pos_x(void);
int					ft_putchar(int c);
int					ft_iscntrl(char c);
void				ft_lstclear_env(t_list **lst);
void				ft_error_bis(void);

	//utils2.c
char				*ft_get_history(void);

	//readline.c
void				ft_del_char(void);
void				ft_add_char(char c);
void				ft_analyse_del(void);
void				ft_analyse_c(char c);
void				ft_readline(void);

	//readline2.c
void				ft_add_to_hist(void);
void				ft_unwrite_line(void);
void				ft_write_line(void);
void				ft_process_arrow_up(void);
void				ft_analyse_escp(void);

	//readline3.c
void				ft_process_arrow_down(void);

	//redirections.c
void				ft_do_redirections(void);

	//terminal.c
void				param_termcap3(void);
void				param_termcap2(void);
void				param_termcap(void);
void				enable_raw_mode(void);

#endif