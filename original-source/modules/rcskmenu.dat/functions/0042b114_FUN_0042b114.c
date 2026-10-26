/*
 * FUN_0042b114 at 0042b114
 * undefined FUN_0042b114(void)
 * Address ranges: 0042b114-0042b17a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b114(int *param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  
  FUN_0040bf7c(*(int *)PTR_DAT_0047c9b0);
  FUN_00414a28((int)param_1);
  FUN_0040f848(*(int **)(DAT_0047d774 + 0x70),(int)param_1);
  FUN_00412378((int)param_1,(char *)0x0);
  uVar1 = extraout_ECX;
  uVar2 = extraout_EDX;
  if (param_1[0x93] != 0) {
    (**(code **)(*(int *)param_1[0x93] + 0xc))();
    uVar1 = extraout_ECX_00;
    uVar2 = extraout_EDX_00;
  }
  if (*(char *)((int)param_1 + 0x217) != '\x01') {
    FUN_0042ecc8(param_1,uVar2,uVar1);
  }
  if ((char)param_1[0x87] == '\0') {
    (**(code **)(*param_1 + 0xc4))();
  }
  return;
}

