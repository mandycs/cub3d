#include "cub_log.h"

int	cub_log(t_log_level level, const char *message)
{
	if (LOGGING)
	{
		if (level == DEBUG)
			bfl_fprintf(STDOUT, "[DEBUG] %s\n", message);
		else if (level == INFO)
			bfl_fprintf(STDOUT, "[INFO] %s\n", message);
		else if (level == WARNING)
			bfl_fprintf(STDERR, "[WARNING] %s\n", message);
		else if (level == ERROR)
			bfl_fprintf(STDERR, "[ERROR] %s\n", message);
	}
	return (1);
}
