/*
 * FUN_00422550 at 00422550
 * undefined FUN_00422550(void)
 * Address ranges: 00422550-00422644
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00422550(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 fVar4;
  
  param_1 = param_1 * 0xa9;
  iVar3 = *(int *)(param_1 + 0xc + DAT_006a5c38) * 0x44;
  iVar1 = iVar3 + DAT_005090d0;
  FUN_0048f4e0();
  uVar2 = __ftol();
  *(undefined4 *)(iVar1 + 0x34) = uVar2;
  *(float *)(param_1 + 0x6c + DAT_006a5c38) =
       (float)(int)(-0x1000 / (longlong)*(int *)(iVar3 + 0x34 + DAT_005090d0));
  *(undefined4 *)(param_1 + 0x68 + DAT_006a5c38) = 0;
  *(undefined4 *)(param_1 + 0x70 + DAT_006a5c38) = 0;
  iVar1 = DAT_005090d0;
  uVar2 = __ftol();
  *(undefined4 *)(iVar3 + 0x24 + iVar1) = uVar2;
  if ((extraout_ST1 == (float10)0.0) && (extraout_ST0 == (float10)0.0)) {
    return;
  }
  fVar4 = (float10)fpatan(extraout_ST0,extraout_ST1);
  *(float *)(iVar3 + 0x1c + DAT_005090d0) =
       (float)(((fVar4 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4) /
              (float10)6.2831855);
  return;
}

