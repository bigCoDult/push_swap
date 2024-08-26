#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

// #include "ft_strlen.c"
// #include "ft_strlcat.c"
// #include "ft_substr.c"
// #include "ft_calloc.c"
// #include "ft_bzero.c"
// #include "ft_memset.c"

#include "libft.h"

int main(void)
{
	int i = 0;
	while (i++ < 10)
	{	
		char *str = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')[i]
		printf("%s", str);	
	}
	// strlcat
		// size_t size = 0;
		// size_t size2 = size;
		// char *dest = NULL;
		// char *dest2 = NULL;
		// const char *src = "1234567";
		// const char *src2 = "1234567";
		// // // char dest[99] = "ABCDEABCDE";
		// // char dest2[99] = "ABCDEABCDE";
		// // char dest[99] = "";
		// // char *dest = NULL;
		// // char dest2[99] = "ABCDEABCDE";
		// // char dest2[99] = "";
		// // const char *src = "1234567";
		// // const char *src = NULL;
		// // const char *src = NULL;
		// // const char *src2 = NULL;
		// // const char *src2 = NULL;
		// printf("\n");
		// printf("실행전\n");
		// printf("dest : %s\n", dest);
		// printf("src : %s\n", src);
		// printf("size : %zu\n", size);
		// printf("\n");
		// printf("strlcat\n");
		// printf("반환값 : %lu\n", strlcat(dest, src, size));
		// printf("dest  : %s\n", dest);
		// printf("src   : %s\n", src);
		// printf("\n");
		// printf("ft_strlcat\n");
		// printf("반환값 : %zu\n", ft_strlcat(dest2, src2, size2));
		// printf("dest2  : %s\n", dest2);
		// printf("src2   : %s\n", src2);
		// printf("\n");

	// strcmp
		// char lhs[99] = "aaaaaaa";
		// char rhs[99] = "aaadefg";
		// int count = 0;
		// while (count++ < 8)
		// {
		//   printf("\n");
		//   printf("strncmp    : %d\n", strncmp(lhs, rhs, count));
		//   printf("ft_strncmp : %d\n", ft_strncmp(lhs, rhs, count));
		// }  
	
	
	
	// substr
		// char *s = "12345";
		// unsigned int start = 10;
		// size_t len = 5;
		
		// // char *s2 = "12345";
		// // unsigned int start2 = 10;
		// // size_t len2 = 5;
		// printf("\n");
		// printf("실행전\n");
		// printf("s : %s\n", s);
		// printf("start : %d\n", start);
		// printf("len : %lld\n", len);
		// printf("\n");
		// printf("substr\n");
		// printf("반환값 : %s\n", ft_substr(s, start, len));
		// printf("start  : %d\n", start);
		// printf("len   : %lld\n", len);
		// printf("\n");
		// printf("ft_substr\n");
		// printf("반환값 : %s\n", ft_substr(s2, start2, len2));
		// printf("start2  : %d\n", start2);
		// printf("len2   : %ld\n", len2);
		// printf("\n");

	return (0);
}
