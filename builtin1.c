#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @infos: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *infos)
{
	print_list(infos->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @infos: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *infos, char *str)
{
	char *pop, c;
	int ret;

	pop = _strchr(str, '=');
	if (!pop)
		return (1);
	c = *pop;
	*pop = 0;
	ret = delete_node_at_index(&(infos->alias),
		get_node_index(infos->alias, node_starts_with(infos->alias, str, -1)));
	*pop = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @infos: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *infos, char *str)
{
	char *pop;

	pop = _strchr(str, '=');
	if (!pop)
		return (1);
	if (!*++pop)
		return (unset_alias(infos, str));

	unset_alias(infos, str);
	return (add_node_end(&(infos->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pop = NULL, *r = NULL;

	if (node)
	{
		pop = _strchr(node->str, '=');
		for (r = node->str; r <= pop; r++)
		_putchar(*r);
		_putchar('\'');
		_puts(pop + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @infos: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *infos)
{
	int i = 0;
	char *pop = NULL;
	list_t *node = NULL;

	if (infos->argc == 1)
	{
		node = infos->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; infos->argv[i]; i++)
	{
		pop = _strchr(infos->argv[i], '=');
		if (pop)
			set_alias(infos, infos->argv[i]);
		else
			print_alias(node_starts_with(infos->alias, infos->argv[i], '='));
	}

	return (0);
}

