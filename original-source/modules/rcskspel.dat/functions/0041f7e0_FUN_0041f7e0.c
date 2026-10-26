/*
 * FUN_0041f7e0 at 0041f7e0
 * undefined FUN_0041f7e0(void)
 * Address ranges: 0041f7e0-0041f861
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041f7e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00429050();
  iVar2 = 0;
  if (iVar1 != 0) {
    if (param_1 != DAT_0053be28) {
      iVar2 = FUN_004be6c9();
      if (iVar2 % 3 != 0) {
        return iVar2 / 3;
      }
    }
    iVar1 = FUN_004be6c9();
    FUN_0049dd20(*(undefined4 *)(&DAT_004e34f8 + (iVar1 % 0xd) * 0x44));
    iVar2 = FUN_0049d870();
    if ((DAT_004e3984 == -1) || (iVar2 == 0)) {
      uVar3 = 0;
      FUN_0049dd20(*(undefined4 *)(&DAT_004e34f8 + (iVar1 % 0xd) * 0x44));
      iVar2 = FUN_0049d780(uVar3);
    }
  }
  return iVar2;
}

