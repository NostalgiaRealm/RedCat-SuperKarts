/*
 * FUN_004380cc at 004380cc
 * undefined __register FUN_004380cc(int * param_1, char param_2)
 * Address ranges: 004380cc-004380db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004380cc(int *param_1,char param_2)

{
  if (param_2 != *(char *)((int)param_1 + 0x32)) {
    *(char *)((int)param_1 + 0x32) = param_2;
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return;
}

