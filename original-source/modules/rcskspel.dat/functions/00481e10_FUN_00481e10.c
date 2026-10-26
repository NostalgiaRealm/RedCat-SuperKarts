/*
 * FUN_00481e10 at 00481e10
 * undefined FUN_00481e10(void)
 * Address ranges: 00481e10-00481e53
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00481e10(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_005450a8;
  if (((DAT_005450a8 != 0) && (0.0 <= param_1)) && (param_1 <= 1.0)) {
    uVar2 = __ftol();
    *(undefined4 *)(iVar1 + 0xa0) = uVar2;
  }
  return;
}

