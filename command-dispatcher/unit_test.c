#include "cmd.h"

void hello_cmd(uint8_t* cmd)
{
  printf("Hello %s\n", cmd);
}

void print_cmd(uint8_t* cmd)
{
  printf("print %s\n", cmd);
}

cmd_table_t cmd_table[] = 
{
  {"hello", hello_cmd},
  {"print", print_cmd},
  {NULL, NULL}
};

int main()
{
  uint8_t cmd_result;
  
  // Test 1: NULL table
  cmd_result = cmd_evaluate(NULL, "hello");
  printf("Test 1: %s\n", cmd_result == CMD_NULL ? "PASS" : "FAIL");

  // Test 2: NULL Input
  cmd_result = cmd_evaluate(cmd_table, NULL);
  printf("Test 2: %s\n", cmd_result == CMD_EMPTY ? "PASS" : "FAIL");

  // Test 3: Valid Command
  cmd_result = cmd_evaluate(cmd_table, "hello");
  printf("Test 3: %s\n", cmd_result == CMD_OK ? "PASS" : "FAIL");

  // Test 4: Invalid Command
  cmd_result = cmd_evaluate(cmd_table, "reboot");
  printf("Test 4: %s\n", cmd_result == CMD_NOT_FOUND ? "PASS" : "FAIL");
  return 0;
}