/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:38:41 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 12:08:22 by ade-garr         ###   ########.fr       */
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

//MINISHELL

enum	type
{
	WORD,
	AND,
	OR,
	SEMICOLON,
	PIPE,
	RIGHT,
	LEFT,
	DRIGHT,
	DLEFT,
	CMD,
};

typedef	struct s_token
{
	char			*s;
	enum type 		type;
}				t_token;

typedef struct		s_cmd
{
	int				pipe_flag;
	t_list			*exec_lst; // LL car env var
	t_list			*rdir_lst; // content = s_rdir
}					t_cmd;

typedef struct	s_node
{
	enum type 		type; 
	t_list			*cmd_lst; // content = t_cmd
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct		s_rdir
{
	int				flag; // 1 == > // 2 == < // 3 == >> // 4 == <<
	char			*file; // attention aux ambiguous redirect  jeej="file    mdr"     $ echo test > $jeej
}					t_rdir;

typedef struct		s_shell
{
	t_list			*env;
	t_list			*cmd; // à changer ?
	t_list			*tmp_cmd; // à changer ?
	t_list			*tmp_dir; // à changer ?
	t_node			*ast;
	char			*line;
	int				child_status;
	pid_t			pid_pipe;
	pid_t			pid_exec;
	int				pipefd[2];
	int				error_flag;
	int				child_flag; // à voir si à garder
	int				return_value; // à voir si à garder
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

	//main.c
t_node				*ft_launch_lexer(char *line);
void				get_list_env(char **env);
void				init_shell(void);
void				ft_exit(void);
int					main(int argc, char **argv, char **env);

	//execute1.c
void				ft_exec_cmd(t_node *node);
void				ft_process_cmd(void);
void				ft_do_pipes(void);
void				ft_do_dup_child(void);
void				ft_do_dup_parent(void);

	//execute2.c
void				launch_execution(t_node *node);

	//expansion.c
char				*find_match_in_env(char *s, int *len, t_list *env);
char				*replace_var(char *s, int i, t_list *env);
char				*expand_content(char *s, t_list *env);
int					check_dollar_sign(char *s);
void				replace_elem(t_token **content, t_list *elem, t_list *prev);

	//expansion2.c
void				expansion_in_exec_lst(t_list *exec_lst, t_list *env);
int					is_ambiguous_redirect(char *s);
void				expansion_in_rdir_lst(t_list *rdir_lst, t_list *env);

	//utils.c
void				ft_incr_pos_x(void);
int					ft_putchar(int c);
int					ft_iscntrl(char c);
void				ft_lstclear_env(t_list **lst);
void				ft_error_bis(void);

	//utils2.c
void				ft_error(void);
char				*ft_get_history(void);
void				ft_do_ctrl_d(void);
void				free_global_struct(void);

	//readline.c
void				ft_del_char(void);
void				ft_add_char(char c);
void				ft_analyse_del(void);
void				ft_analyse_c(char c);
void				ft_readline(void);

	//utils3.c
int					is_space(char c);
int					is_escaped(char *s, int pos);
int					is_special(char *s, int i);
int					which_operator(char *s, int i);
void				skip_spaces(char *str, int *i);

	//utils4.c
void				skip_to_next_valid_quote(char *s, int *i);
t_token				**free_lexer(t_token **lexer);
char				*join_three_str(char *s1, char *s2, char *s3);

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

	//lexer.c
t_token				*new_token(char *s);
t_token				*build_token(char *s, int *i);
int					word_count(char *s);
t_token				**ft_lexer(char *s);

	//parser1.c
int					syntax_err(t_token **lexer, int	i);
int					syntax_check(t_token **lexer);
int					find_separator(t_token **lexer);
t_node				*ft_new_node(enum type type, t_list *cmd_lst);
t_node				*parser(t_token **lexer);

	//parser2.c
int					add_to_cmd_lst(t_cmd **cmd, t_list **cmd_lst, int pipe_flag);
int					add_to_rdir_lst(t_token **lexer, int *i, t_cmd *cmd);
int					add_to_exec_lst(t_token **lexer, t_cmd *cmd, int i);
t_node				*build_node(t_token **lexer);
t_node				*build_tree(t_token **lexer);

	//quotes.s
char				*make_unquoted_str(char *s, int *i);
void				quotes_removal(char **s);

	//free_ast.c
void				free_rdir(t_rdir *rdir);
void				free_cmd(t_cmd *cmd);
void				free_cmd_lst(t_list *cmd_lst);
void				free_node(t_node *node);
void				free_ast(t_node *ast);

	//ft_isprint_safe.c
int					ft_isprint_safe(int c);

	//ft_strdup_safe.c
char				*ft_strdup_safe(const char *s);

	//ft_strlen_safe.c
size_t				ft_strlen_safe(const char *s);

// PRINT_LEXER_PARSER.C -- to delete before eval
void	print_lexer(t_token **lexer, char *s);
void	print_exec_lst(t_list *exec_lst);
void	print_rdir_lst(t_list *rdir_lst);
void	print_children(t_node *node, int tree_pos);
void	print_ast_node(t_node *node, int tree_pos);
void	print_parser(t_node *ast);

#endif