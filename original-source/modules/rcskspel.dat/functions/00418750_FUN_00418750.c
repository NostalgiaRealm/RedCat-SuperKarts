/*
 * FUN_00418750 at 00418750
 * undefined FUN_00418750(void)
 * Address ranges: 00418750-00418767
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00418750(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  if (*piVar1 == -1) {
    *piVar1 = param_3;
  }
  return;
}

