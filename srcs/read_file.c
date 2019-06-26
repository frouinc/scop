#include <scop.h>

char *read_file(const char *filename)
{
	char *buffer = 0;
	long length;
	FILE *f = fopen(filename, "rb");

	if (f)
	{
		if (fseek(f, 0, SEEK_END) == -1
			|| (length = ftell(f)) == -1
			|| fseek(f, 0, SEEK_SET) == -1
			|| (buffer = malloc(length + 1)) == NULL)
		{
			fclose(f);
			return (NULL);
		}
		if (fread(buffer, 1, length, f) < length)
		{
			free(buffer);
			fclose(f);
			return (NULL);
		}
		buffer[length] = 0;
		fclose(f);
	}
	else
	{
		return (NULL);
	}
	return (buffer);
}