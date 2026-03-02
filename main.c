/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:36:03 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/02 12:32:17 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*asign(t_list *a)
{
	t_stack	*stack;
	t_bench	*bench;

	stack = ft_calloc(sizeof (t_stack), 1);
	bench = ft_calloc(sizeof (t_bench), 1);
	stack -> calc = bench;
	stack -> stacka = a;
	return (stack);
}

static int	found_flag(t_flags *flag, int pos)
{
	t_flags	*aux;

	aux = flag;
	while (aux)
	{
		if (aux -> num == pos)
			return (1);
		aux = aux -> next;
	}
	return (0);
}

static void	asign_bench(t_stack *sta, char *l, char *s, float d)
{
	sta -> calc -> disorder = d;
	sta -> calc -> flag = l;
	sta -> calc -> strategy = s;
}

static void	execute(t_stack *sta, t_flags *flags)
{
	float	d;

	d = disorder(sta -> stacka);
	if (found_flag(flags, 0))
	{
		asign_bench(sta, "Simple", "O(n^2)", d);
		simple(&sta);
	}
	else if (found_flag(flags, 1))
	{
		asign_bench(sta, "Medium", "O(n^2)", d);
		medium(&sta);
	}
	else if (found_flag(flags, 2))
	{
		asign_bench(sta, "Complex", "O(n log n)", d);
		complex(&sta);
	}
	else
	{
		asign_bench(sta, "Adaptive", sel_strat(d), d);
		adaptiv(&sta);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_stack	*stack;
	t_flags	*flags;
	char	*s;

	flags = NULL;
	if (argv < 1)
		return (0);
	argv++;
	stacka = parser(argv, &flags, 2);
	if (!stacka)
		return (0);
	stack = asign(stacka);
	execute(stack, flags);
	ft_flaclear(&flags);
	free_stack(&stack);
	if (found_flag(flags, 4))
		print_bench(stack -> calc);
	return (0);
}

/*
int main(int argc, char **argv)
{
    // 1. Validar argumentos (son números?)
    // 2. Detectar duplicados
    // 3. Crear estructura t_stack
    // 4. Inicializar stacks con los números
    // 5. Llamar al algoritmo de ordenamiento
    // 6. Liberar memoria
    t_stack *stack;
    int     size;

    // ... parseo de argumentos y validación ...

    // Inicializar estructura
    stack = ft_init_stack(argv, argc);
    if (!stack)
        return (1);

    size = argc - 1;
    // ✅ USAR ESTA LÓGICA:
    if (is_sorted(stack->stacka))
    {
        // Ya está ordenado, no hacer nada
    }
    else
        ordenar

    // Liberar memoria
    free_stack(&stack);

    return (0);
}
Función is_valid_number(char *str) → verifica que sea número
Función has_duplicates(argv) → detecta duplicados
Función ft_init_stack(argv, argc) → crea la estructura

///// PROBAR SIMPLEEEEE
#include "push_swap.h" // Asegúrate de que este incluya libft.h y structur.h

// Función rápida para crear nodos usando TU ft_lstnew
t_list	*create_node(int n)
{
	return (ft_lstnew(n));
}

// Función para imprimir tus stacks con TU estructura
void	print_status(t_stack *stack)
{
	t_list	*a = stack->stacka;
	t_list	*b = stack->stackb;

	printf("\n[ STACK A ]: ");
	while (a)
	{
		printf("%d ", a->num);
		a = a->next;
	}
	printf("\n[ STACK B ]: ");
	while (b)
	{
		printf("%d ", b->num);
		b = b->next;
	}
	printf("\n--------------------------\n");
}

int	main(void)
{
	t_stack	*stack;

	// 1. Inicializamos la estructura principal
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	stack->stacka = NULL;
	stack->stackb = NULL;
	
	// Inicializamos el bench por si tus funciones de movimiento lo usan
	stack->calc = ft_calloc(1, sizeof(t_bench));

	// 2. Creamos el Stack A manualmente para probar el "simple"
	// Ejemplo: 5, 1, 4, 2, 3
	ft_lstadd_back(&stack->stacka, ft_lstnew(5));
	ft_lstadd_back(&stack->stacka, ft_lstnew(1));
	ft_lstadd_back(&stack->stacka, ft_lstnew(4));
	ft_lstadd_back(&stack->stacka, ft_lstnew(2));
	ft_lstadd_back(&stack->stacka, ft_lstnew(3));

	printf("ESTADO INICIAL:");
	print_status(stack);

	// 3. Ejecutamos tu algoritmo simple
	simple(&stack);

	printf("ESTADO FINAL (Ordenado):");
	print_status(stack);

	// 4. Limpieza básica (opcional para el test)
	// ft_lstclear(&stack->stacka);
	// free(stack->calc);
	// free(stack);

	return (0);
}
*/