/*
 * FUN_0044af64 at 0044af64
 * undefined __register FUN_0044af64(void)
 * Address ranges: 0044af64-0044b024
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044af64(void)

{
  int *piVar1;
  int in_stack_00000004;
  POINT local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(in_stack_00000004 + -4);
  local_c = piVar1[2];
  local_8 = piVar1[1];
  local_14 = *piVar1;
  local_10 = piVar1[3];
  FUN_00417bbc(*(int **)(*(int *)(in_stack_00000004 + -8) + 0x10),
               *(undefined4 *)(in_stack_00000004 + -0xc));
  local_2c.x = local_14;
  local_2c.y = local_10;
  local_24 = *piVar1;
  local_20 = piVar1[1];
  local_1c = local_c;
  local_18 = local_8;
  FUN_0041863c(*(int **)(in_stack_00000004 + -8),&local_2c,2);
  FUN_00417bbc(*(int **)(*(int *)(in_stack_00000004 + -8) + 0x10),
               *(undefined4 *)(in_stack_00000004 + 0xc));
  local_1c = local_14 + -1;
  local_2c.x = local_c;
  local_2c.y = local_8;
  local_24 = piVar1[2];
  local_20 = piVar1[3];
  local_18 = local_10;
  local_14 = local_1c;
  FUN_0041863c(*(int **)(in_stack_00000004 + -8),&local_2c,2);
  return;
}

