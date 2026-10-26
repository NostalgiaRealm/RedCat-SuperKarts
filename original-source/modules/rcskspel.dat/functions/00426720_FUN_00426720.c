/*
 * FUN_00426720 at 00426720
 * undefined FUN_00426720(void)
 * Address ranges: 00426720-00426777
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426720(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  param_1 = param_1 + -4;
  if (param_1 < 0) {
    param_1 = 0;
  }
  iVar1 = param_1 * -0x10 + 200;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  uVar2 = iVar1 << 0x18 | 0x404040;
  *(uint *)(param_2 + 0x10) = uVar2;
  *(uint *)(param_3 + 0x30) = uVar2;
  *(uint *)(param_3 + 0x10) = uVar2;
  *(uint *)(param_2 + 0x30) = uVar2;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_3 + 0x34) = 0;
  *(undefined4 *)(param_3 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x34) = 0;
  return;
}

