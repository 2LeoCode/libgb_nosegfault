#include <garbage.h>

int	gb_alloc_and_push(void *data_addr, size_t size)
{
	void	**ptr;

	ptr = (void **)data_addr;
	*ptr = malloc(size);
	if (!*ptr)
		return (gb_erorr());
	return (garbage(*ptr, free, push));
}

int	gb_calloc_and_push(void *data_addr, size_t size)
{
	void		**ptr;
	unint64_t	*longptr;
	char		*charptr;

	ptr = (void **)data_addr;
	*ptr = malloc(size);
	if (!*ptr)
		return (gb_error());
	longptr = (uint64_t *)*ptr;
	while (size > 8)
	{
		*longptr++ = 0;
		size -= 8;
	}
	charptr = (char *)longptr;
	while (size--)
		*charptr++ = 0;
	return (garbage(*ptr, free, push));
}
