/*
** lem.h for lem in /home/kauch_j/rendu/prog_elem/lem_in
** 
** Made by quach_a
** Login   <quach_a@epitech.net>
** 
** Started on  Tue Apr 15 13:27:03 2014 quach_a
** Last update Sun May  4 17:50:36 2014 kauch_j
*/

#ifndef		LEM_H_
# define	LEM_H_

# define READ_SIZE	4096

typedef struct	s_lem
{
  char		*name;
  int		type;
  int		ant;
  int		ant_num;
  int		link;
  int		*pipe;
}		t_lem;

typedef struct	s_stock
{
  int		end;
  int		r;
}		t_stock;

/*
 * check_error
 */
int		check_error(t_lem *, char **, int);

/*
 * my_str_to_wordtab
 */
char		**my_str_to_wordtab(char *, char);

/*
 * xmalloc
 */
char		*xmalloc(char *, int);

/*
 * algo
 */

int		check_end(t_lem *, int);
int		start_algo(int, t_lem *);

/*
 * solve
 */

int		solve(t_lem *, int, int *, t_stock);
int		if_one_way(t_lem *, int, int *, t_stock);
int		multiple_ways(t_lem *, int, int *, t_stock);
void		aff_path(t_lem *, int, int *);

/*
 * set_link
 */
void		set_link(t_lem *);

/*
 * get_pipe
 */
char		**put_pipe(char *, int);
int		check_all_name(t_lem *, char *, char *, int);
void		copy_name(char **, char *, char *, int);
char		**get_pipe(t_lem *, char **);
char		**get_all_elem(t_lem *, char *);

/*
 * get_pipe_number
 */
int		get_pipe_number(char **);

/*
 * check_name
 */
int		check_name(t_lem *, char *);

/*
 * find_pipe
 */
int		set_reverse_pipe(t_lem *, char *, int, int);
int		reverse_pipe(t_lem *, char *, char *);
int		set_pipe(t_lem *, char *, char *, int);
void		find_pipe(t_lem *, char **, int, int);

/*
 * pipe_get_function
 */
char		*get_name(char *);
int		k_get_link_value(t_lem *, int, int);
int		get_value(t_lem *, char *);
int		get_value_reverse(t_lem *, char *);

/*
 * pipe_check_function
 */
int		check_same(char *, char *);
int		is_already_here(t_lem *, char *, int);

/*
 * is_num
 */
int		is_num(char);

/*
 * ants
 */
int		go_forward(int *, t_lem *, int);
void		init_ant_num(int *, t_lem *, int);
int		to_the_exit(int *, t_lem *, int);

/*
 * get_ants
 */
int		get_ants(char *, t_lem *, int);

/*
 * count_len
 */
int		count_len(int, int, char *);

/*
 * aff_str
 */
void		aff_str(char *, int);

/*
 * define_name
 */
int		get_stanend(char *, t_lem *, int, int);
int		define_name(char *, int, int, t_lem *);
int		find_name(char *, int, int, t_lem *);
int		find_room(char *);
void		put_name(t_lem *, char *);

/*
 * functions_str
 */
char		*my_strcat(char *, char *);
char		*my_strcpy(char *, char *);
char		*my_strncpy(char *, char *, int);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);

/*
 * functions
 */
void		my_putnbr(int);
int		my_strlen(char *);
int		my_getnbr(char *);
void		my_putchar(char);
void		my_putstr(char *);

/*
 * main
 */
int		check_stanend(t_lem *, int);
char		*init_room(t_lem *, int);
int		my_lem(int, char *);
char		*read_it();

#endif		/* !LEM_H_ */
