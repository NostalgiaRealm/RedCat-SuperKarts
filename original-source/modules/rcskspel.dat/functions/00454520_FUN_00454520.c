/*
 * FUN_00454520 at 00454520
 * undefined FUN_00454520(void)
 * Address ranges: 00454520-00454559
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454520(undefined4 param_1,undefined1 param_2)

{
  int *piVar1;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_10 [16];
  
  local_18 = param_1;
  local_14 = 0;
  piVar1 = (int *)FUN_004547f0(local_10,&local_18);
  *(undefined1 *)(*piVar1 + 0x10) = param_2;
  return;
}

