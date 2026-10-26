/*
 * FUN_004c88ca at 004c88ca
 * undefined FUN_004c88ca(void)
 * Address ranges: 004c88ca-004c890d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c88ca(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_006b6740 = _DAT_006b6740 + 1;
  pvVar1 = _malloc(0x1000);
  param_1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}

