#include "cmd.h"

uint8_t cmd_evaluate(cmd_table_t* cmd_table, uint8_t* cmd_in)
{
  if (cmd_table == NULL)
    return CMD_NULL;
  if (cmd_in == NULL)
    return CMD_EMPTY;
  uint8_t cmd_len = 0;
  while(cmd_in[cmd_len] != '\n' && cmd_in[cmd_len] != '\0' && cmd_in[cmd_len] != ' ')
  {
    cmd_len++;
  }

  if(cmd_len == 0) return CMD_EMPTY;
  if(cmd_len > CMD_MAX_LENGTH) return CMD_OUT_OF_SIZE;
  
  uint8_t i = 0;
  while(cmd_table[i].cmd_name != NULL)
  {
    if (strncmp(cmd_table[i].cmd_name, (const char*)cmd_in, cmd_len) == 0
        && cmd_table[i].cmd_name[cmd_len] == '\0')
    {
      cmd_table[i].cmd(cmd_in);
      return CMD_OK;
    }
    i++;
  }
  return CMD_NOT_FOUND;
}