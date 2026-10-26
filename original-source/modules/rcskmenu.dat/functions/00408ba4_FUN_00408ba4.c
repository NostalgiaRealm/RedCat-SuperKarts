/*
 * FUN_00408ba4 at 00408ba4
 * undefined __register FUN_00408ba4(undefined4 * param_1, undefined4 param_2, undefined4 param_3, double param_4)
 * Address ranges: 00408ba4-00408be3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00408ba4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,double param_4)

{
  ulonglong uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int iStack_8;
  
  uVar1 = (ulonglong)ROUND(param_4 * (double)_DAT_0047b168);
  local_c = (int)uVar1;
  iStack_8 = (int)(uVar1 >> 0x20);
  if ((longlong)uVar1 < 0) {
    uVar1 = CONCAT44(-(uint)(local_c != 0) - iStack_8,-local_c);
    uVar3 = (undefined4)(uVar1 % (ulonglong)DAT_0047b16c);
    iVar2 = -(int)(uVar1 / DAT_0047b16c);
  }
  else {
    iVar2 = (int)(uVar1 / DAT_0047b16c);
    uVar3 = (undefined4)(uVar1 % (ulonglong)DAT_0047b16c);
  }
  *param_1 = uVar3;
  param_1[1] = iVar2 + 0xa955a;
  return;
}

