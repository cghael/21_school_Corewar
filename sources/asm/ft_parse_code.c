#include "asm.h"

uint8_t	*ft_parse_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buffer;
	uint8_t	byte;

	if (!(buffer = ft_memalloc(len)))
		ft_terminate(ERR_CODE_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		ft_terminate(ERR_READ_FILE);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		ft_terminate(ERR_INVALID_FILE);
	return (buffer);
}