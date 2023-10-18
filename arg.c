#include "shell.h"

/**
 * tokenize_and_parse - tokenize and parse input into arguments
 * @input: input string
 * @delimiter: delimiter
 * @parsed_args: parsed arguments vector
 * @mode: parsing mode (0 for character delimiter, 1 for string delimiter)
 *
 * Return: none
 */
void tokenize_and_parse(char *input, const char *delimiter,
		char ***parsed_args, int mode)
{
	char *tokenized = NULL, **temp_args, *trimmed_arg;
	int arg_index = 0, i;

	*parsed_args = NULL;
	tokenized = _strtok(input, delimiter, mode);

	while (tokenized != NULL)
	{
	temp_args = (char **)_malloc((_arlen(*parsed_args) + 2) * sizeof(char *));

	if (!*parsed_args)
		*parsed_args = temp_args;
	else
	{
		i = 0;
	while ((*parsed_args)[i])
	{
		temp_args[i] = _strdup((*parsed_args)[i]);
		i++;
	}
	free_pp(*parsed_args);
	*parsed_args = temp_args;
	}
	(*parsed_args)[arg_index] = NULL;
	trimmed_arg = tokenized;

	if ((tokenized[0] == '"' && tokenized[_strlen(tokenized) - 1] == '"') ||
		(tokenized[0] == '\'' && tokenized[_strlen(tokenized) - 1] == '\''))
	{
		trimmed_arg = _strdup(tokenized + 1);
		trimmed_arg[_strlen(trimmed_arg) - 1] = '\0';
	}

	trim_spaces(&((*parsed_args)[arg_index]), trimmed_arg);
	(*parsed_args)[arg_index + 1] = NULL;
	if (trimmed_arg != tokenized)
		free(trimmed_arg);
	tokenized = _strtok(NULL, delimiter, mode);
	arg_index++;
	}
}
