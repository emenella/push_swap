#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_cmd
{
	char			*content;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_slack
{
	t_list	*lst;
	int		size;
}				t_slack;

void	swap(t_slack *slack);
void	swap_a_b(t_slack *a, t_slack *b);
void	ft_swap(int *a, int *b);
void	push(t_slack *dest, t_slack *src);
void	rotate(t_slack *slack);
void	rotate_a_b(t_slack *a, t_slack *b);
void	reverse_rotate(t_slack *slack);
void	reverse_rotate_a_b(t_slack *a, t_slack *b);
t_slack	*ft_init_slack(int size);
void	print_slack(t_slack *a, t_slack *b);
void	ft_putchar(char c);
int		ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstfree(t_list *lst, t_list **alst);
void	ft_listfree(t_list *lst);
void	ft_cmdadd_back(t_cmd **alst, t_cmd *new);
int		ft_cmdsize(t_cmd *lst);
t_cmd	*ft_cmdnew(char *content);
t_cmd	*ft_cmdlast(t_cmd *lst);
void	ft_cmdfree(t_cmd *lst);
int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
int		get_next_line(char **line);
void	ft_exec_operation(int operation, t_slack *a, t_slack *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_cmd_to_operation(char *cmd);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
void	ra(t_slack *a);
void	rb(t_slack *b);
void	rr(t_slack *a, t_slack *b);
void	rra(t_slack *a);
void	rrb(t_slack *b);
void	rrr(t_slack *a, t_slack *b);
void	pa(t_slack *a, t_slack *b);
void	pb(t_slack *a, t_slack *b);
void	sa(t_slack *a);
void	sb(t_slack *b);
void	ss(t_slack *a, t_slack *b);
void	push_min_to_b(t_slack *a);
void	push_max_to_b(t_slack *a);
void	push_max_to_a(t_slack *b);
void	sort_3(t_slack *a);
void	sort_5(t_slack *a, t_slack *b);
void	sort_100(t_slack *a, t_slack *b);
void	sort_500(t_slack *a, t_slack *b);
#endif