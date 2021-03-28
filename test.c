#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

// int main(int argc, char **argv, char **env)
// {
// 	(void)argc;
// 	(void)argv;
	// int tab[2];
 
	// pipe(tab);
	// printf("%d\n", tab[0]);
	// printf("%d\n", tab[1]);
	// return (0);


	// pid_t   pid;
	// int     status;
	// pid = fork();
	// if (pid == 0)
	// {
	//     exit(200);
	// }
	// else
	// {
	//     pid = waitpid(-1, &status, 0);
	//     printf("pid = %d\n", pid);
	//     printf("$? = %d\n", WEXITSTATUS(status));
	//     printf("status = %d\n", status);
	//     return(0);
	// }

	// pid_t   pid;
	// int     a;
	// int		b;
	// int		*ptr;

	// a = 0;
	// b = 20;
	// ptr = &a;
	// pid = fork();
	// if (pid == 0)
	// 	ptr = &b;
	// printf("%d\n", *ptr);

	// char buf[10];
	// read(0, buf, 10);
	// //write(0,"echo test", 5);
	// write(1, buf, 5);
	// write(1, "\n", 1);
	// printf("%s\n", buf);
	// //printf("%s", buf);

	// int	ret;

	// ret = tgetent(NULL, getenv("TERM"));
	// if (ret == 0 || ret == -1)
	// 	printf("tgetent pas ok\n");
	// else
	// 	printf("tgetent ok\n");

	// char *arw_u;

	// arw_u = tgetstr("ku", NULL);
	// if (arw_u == NULL)
	// 	printf("arrow up pas ok\n");
	// else
	// 	printf("arrow up ok\n");
	
	// printf("%s\n", arw_u);

	// unsigned char buf[10];
	// read(0, buf, 10);
	// printf("%d\n", (unsigned int)buf[2]);
	// return (0);

	// char			*del;
	// char			*delm;
	// char 			buf[10];
	// // int				ret;
	// struct termios	termios_p;
	// struct termios	old_termios_p;

	// ret = tcgetattr(0, &termios_p);
	// termios_p.c_lflag &= ~ECHO;
	// ret = tcsetattr(0, TCSAFLUSH,  &termios_p);
	// del = tgetstr("kD", NULL);
	// delm = tgetstr("dm", NULL);

	// if (ret == 0)
	// 	printf("tcsetattr ok\f\n");
	// else 
	// 	printf("tcsetattr pas ok\f\n");
	
	// while (1)
	// {
	// 	read(0, buf, 10);
	// 	write(1, &buf[0], 1);
	// 	if ((int)buf[0] == 127)
	// 	{
	// 		// tputs(delm, 1, ft_putchar);
	// 		tputs(del, 1, ft_putchar);
	// 	}
	// 	if (buf[0] == 'b')
	// 		break;
	// }
	// // ret = tcsetattr(0, TCSANOW, &old_termios_p);
	// return (0);



/////////////////////////////////////////////////////////////////////
///TESTER TERMIOS + WRITE INPUTS
/////////////////////////////////////////////////////////////////////


// struct termios orig_termios;

// int	ft_putchar(int c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// char	ctrl_q(char c)
// {
// 	c = c & 0x1f;
// 	return (c);
// }

// void	ft_error()
// {
// 	printf("%s\n", strerror(errno));
// 	//ft_exit();
// 	exit (1);
// }

// int		ft_iscntrl(char c)
// {
// 	if ((int)c >= 0 && (int)c <= 31 || (int)c == 127)
// 		return (1);
// 	return (0);
// }

// void 	disable_raw_mode()
// {
// 	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
// 		ft_error();
// }

// void	enable_raw_mode() 
// {
// 	struct termios raw;

// 	if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
// 		ft_error();
// 	raw = orig_termios;
// 	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
// 	raw.c_oflag &= ~(OPOST);
// 	raw.c_cflag |= (CS8);
// 	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
// 	raw.c_cc[VMIN] = 0;
// 	raw.c_cc[VTIME] = 1;
// 	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
// 		ft_error();
// }

// int		main() 
// {
// 	char	c;
// 	int		ret;
// 	char 	*del_line;
// 	char	*left;
// 	char	*left2;

// 	ret = tgetent(NULL, getenv("TERM"));
// 	del_line = tgetstr("dc", NULL);
// 	left = tgetstr("le", NULL);
// 	left2 = tgetstr("bc", NULL);
// 	c = '\0';
// 	enable_raw_mode();
// 	while (1) 
// 	{
// 		if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
// 			ft_error();
// 		if (c == 'a')
// 			// tputs(left, 1, ft_putchar);
// 			tputs(left2, 1, ft_putchar);
// 		else if (c == 127)
// 		{
// 			tputs(left, 1, ft_putchar);
// 			tputs(left2, 1, ft_putchar);
// 		}
// 		else
// 			write(1, "lol", 3);
// 		// if (ft_iscntrl(c) == 1)
// 		// 	printf("%d\r\n", c);
// 		// else
// 		// 	printf("%d ('%c')\r\n", c, c);
// 		if (c == ctrl_q('a'))
// 			break;
// 	}
// 	disable_raw_mode();
// 	return (0);
// }



/////////////////////////////////////////////////////////////////////
///TESTER UN BOOLEEN
/////////////////////////////////////////////////////////////////////

// int		main()
// {
// 	int	bs_flag;
// 	int	ret;

// 	ret = tgetent(NULL, getenv("TERM"));
// 	bs_flag = tgetflag("bs");
// 	printf("%d\n", bs_flag);
// 	return (0);
// }



/////////////////////////////////////////////////////////////////////
///TESTER TGOTO
/////////////////////////////////////////////////////////////////////


struct termios orig_termios;

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

char	ctrl_q(char c)
{
	c = c & 0x1f;
	return (c);
}

void	ft_error()
{
	printf("%s\n", strerror(errno));
	//ft_exit();
	exit (1);
}

void 	disable_raw_mode()
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		ft_error();
}

void	enable_raw_mode() 
{
	struct termios raw;

	if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
		ft_error();
	raw = orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		ft_error();
}

int		main() 
{
	char	c;
	int		ret;
	char 	*ch;
	int		nb_col;

	ret = tgetent(NULL, getenv("TERM"));
	ch = tgetstr("ch", NULL);
	nb_col = tgetnum("co");
	printf("%d\n", nb_col);
	c = '\0';
	enable_raw_mode();
	while (1) 
	{
		if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
			ft_error();
		if (c == 'a')
			tputs(tgoto(ch, 0, 107), 1, ft_putchar);
		if (c == ctrl_q('a'))
			break;
	}
	disable_raw_mode();
	return (0);
}
