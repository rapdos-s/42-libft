# 42-libft
Minha versão da reimplementação de algumas funções básicas da linguagem C.

### Como está o andamento desse repositório?

**Mandatório**

- [ ] ft_isalpha
- [ ] ft_isdigit
- [ ] ft_isalnum
- [ ] ft_isascii
- [ ] ft_isprint
- [ ] ft_strlen
- [ ] ft_memset
- [ ] ft_bzero
- [ ] ft_memcpy
- [ ] ft_memmove
- [ ] ft_strlcpy
- [ ] ft_strlcat
- [ ] ft_toupper
- [ ] ft_tolower
- [ ] ft_strchr
- [ ] ft_strrchr
- [ ] ft_strncmp
- [ ] ft_memchr
- [ ] ft_memcmp
- [ ] ft_strnstr
- [ ] ft_atoi
- [ ] ft_calloc
- [ ] ft_strdup
- [ ] ft_substr
- [ ] ft_strjoin
- [ ] ft_strtrim
- [ ] ft_split
- [ ] ft_itoa
- [ ] ft_strmapi
- [ ] ft_striteri
- [ ] ft_putchar_fd
- [ ] ft_putstr_fd
- [ ] ft_putendl_fd
- [ ] ft_putnbr_fd

**Bônus**

- [ ] ft_lstnew_bonus
- [ ] ft_lstadd_front_bonus
- [ ] ft_lstsize_bonus
- [ ] ft_lstlast_bonus
- [ ] ft_lstadd_back_bonus
- [ ] ft_lstdelone_bonus
- [ ] ft_lstclear_bonus
- [ ] ft_lstiter_bonus
- [ ] ft_lstmap_bonus

**Outros Pontos**

- [x] ~~Makefile~~
- [ ] norminette

### O que precisa?

- ar
- clang
- echo
- make
- rm

### Como usar:

Escreva um teste, exemplo:

`main.c`
```c
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello, World!\n", 1);
    return (0);
}
```

para compilar a biblioteca, utilize

```sh
make
```

Para compilar a main.c com a biblioteca

```sh
cc main.c -L. -lft
```

Para executar
```sh
./a.out
```

A saída esperada é essa
```
Hello, World!
```

## Detalhando um pouco mais as funções

<details>
  </br>
  <summary>ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii e ft_isprint</summary>

Essas funções são responsáveis por verificar se um caractere (no caso, um int) possui determinada característica.

Caso negativo, essas funções retornam 0, caso positivo, retornam um valor não zero, sendo que cada função possui um retorno próprio (o que pode mudar dependendo de qual biblioteca você está usando, aqui estou me baseando na LibC que encontrei nos computadores da 42 São Paulo).

Retorno de cada função:
```
ft_isalpha(): 1024
ft_isdigit(): 2048
ft_isalnum(): 8
ft_isascii(): 1
ft_isprint(): 16384
```
A ideia desses retornos é tornar possível o armazenamento dos resultados de todos os testes em uma única variável int, o que é bem útil para sistemas com memória limitada.

Abaixo um exemplo de código para ver como os valores de retorno são armazenados:

```c
#include <stdio.h>
#include "libft.h"

/**
 * @brief Print the return value of the function in decimal and binary.
 * 
 * @param n The return value to be printed.
 */
static void	print_return_value(int return_value);

int main(void)
{
	int	alpha;
	int	digit;
	int	return_value;

	alpha = 'a';
	digit = '1';
	printf("% 6d = ft_isalpha('%c')\n", ft_isalpha(alpha), (char)alpha);
	printf("% 6d = ft_isdigit('%c')\n", ft_isdigit(digit), (char)digit);
	printf("% 6d = ft_isalnum('%c')\n", ft_isalnum(alpha), (char)alpha);
	printf("% 6d = ft_isascii('%c')\n", ft_isascii(alpha), (char)alpha);
	printf("% 6d = ft_isprint('%c')\n", ft_isprint(alpha), (char)alpha);
	printf("\n");
	printf("Verificando todas as funções com '%c' e guardando o \n", alpha);
	printf("retorno em uma única variável int.\n");
	return_value = 0;
	return_value = ft_isalpha(alpha);
	print_return_value(return_value);
	return_value |= ft_isdigit(alpha);
	print_return_value(return_value);
	return_value |= ft_isalnum(alpha);
	print_return_value(return_value);
	return_value |= ft_isascii(alpha);
	print_return_value(return_value);
	return_value |= ft_isprint(alpha);
	print_return_value(return_value);
	printf("\n");
	printf("Obs.1: Note que o segundo teste não altera o valor\n");
	printf("Obs.2: Nem todos os bits são usados pois a libft não possui\n");
	printf("       todas as funções de checagem de caracteres de libC.\n");
}

static void	print_return_value(int return_value)
{
	int	i;

	printf("return_value = % 6d / 0b", return_value);
	i = 15;
	while (i >= 0)
	{
		printf("%d", (return_value >> i) & 1);
		i--;
	}
	printf("\n");
}

```

A saída esperada:
```
  1024 = ft_isalpha('a')
  2048 = ft_isdigit('1')
     8 = ft_isalnum('a')
     1 = ft_isascii('a')
 16384 = ft_isprint('a')

Verificando todas as funções com 'a' e guardando o 
retorno em uma única variável int.
return_value =   1024 / 0b0000010000000000
return_value =   1024 / 0b0000010000000000
return_value =   1032 / 0b0000010000001000
return_value =   1033 / 0b0000010000001001
return_value =  17417 / 0b0100010000001001

Obs.1: Note que o segundo teste não altera o valor
Obs.2: Nem todos os bits são usados pois a libft não possui
       todas as funções de checagem de caracteres de libC.
```
</details>
