/*
 * FUN_0040f96c at 0040f96c
 * undefined FUN_0040f96c(void)
 * Address ranges: 0040f96c-0040f9cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f96c(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_18;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0040fa70((int)piVar1);
  uStackY_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_18;
  FUN_00402eac((int *)piVar1[1]);
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  *in_FS_OFFSET = uStackY_18;
  FUN_0040fad4((int)piVar1);
  uStackY_18 = 0x40f9cd;
  DeleteCriticalSection((LPCRITICAL_SECTION)(piVar1 + 2));
  return;
}

