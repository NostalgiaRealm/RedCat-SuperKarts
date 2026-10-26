/*
 * FUN_004360cc at 004360cc
 * undefined FUN_004360cc(void)
 * Address ranges: 004360cc-004360e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004360cc(int *param_1,int param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x34))();
  if (cVar1 != '\0') {
    FUN_004380dc((int *)param_1[6],param_2);
  }
  return;
}

