/*
 * FUN_0043a900 at 0043a900
 * undefined FUN_0043a900(void)
 * Address ranges: 0043a900-0043a948
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0043a900(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x1c) + -4;
  uVar2 = iVar1 - *(int *)(param_1 + 0x14) >> 2;
  if ((int)uVar2 < 0) {
    uVar3 = -(0x3ff - uVar2 >> 10);
  }
  else {
    uVar3 = uVar2 >> 10;
  }
  if (uVar3 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x20) + uVar3 * 4) + (uVar2 + uVar3 * -0x400) * 4;
  }
  return iVar1;
}

