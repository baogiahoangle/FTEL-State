#ifndef __CMD_H
#define __CMD_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define CMD_MAX_LENGTH  20

#define CMD_OK          0
#define CMD_EMPTY       1
#define CMD_NULL        2
#define CMD_OUT_OF_SIZE 3
#define CMD_NOT_FOUND   4

typedef void (*cmd_function)(uint8_t*);

typedef struct
{
  char *cmd_name;
  cmd_function cmd;
} cmd_table_t;

uint8_t cmd_evaluate(cmd_table_t* cmd_table, uint8_t* cmd_in);

#endif