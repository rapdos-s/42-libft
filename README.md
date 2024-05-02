# 42-libft
Minha versão da reimplementação de funções básicas da linguagem C.

O que precisa?
cc
make
ar
rm

Como usar:

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
```sh
Hello, World!
```