#ifndef GBLIST_H
# define GBLIST_H

# include <stdlib.h>

typedef void	(*t_destructor)(void *);

typedef struct s_garbage_list
{
	void					*data;
	t_destructor			destructor;
	struct s_garbage_list	*next;
}	t_gblst;

int	gblst_push(t_gblst **lst_ptr, void *data, t_destructor destructor);
void	gblst_pop(t_gblst **lst_ptr);
void	gblst_clear(t_gblst **lst_ptr);

#endif
