#include "solong.h"

int	main(int argc, char *argv[])
{
//	if (argc != 2)
//	{
//		printf("type => \"./so_long <map file>\"\n");
//		exit(1);
//	}

	// 빠른 컴파일을 위해 임시로 맵파일명 설정해둠
	char	*mapfile = "../map/test.ber";
	map_valid_check(mapfile);
	return (0);
}

int	open_map(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\nmap open error. check the map file's name.\n");
		exit(1);
	}
	return (fd);
}
