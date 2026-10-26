/*
 * FUN_00447844 at 00447844
 * undefined FUN_00447844(void)
 * Address ranges: 00447844-00447857
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00447844(int param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = CONCAT31((int3)((uint)*(int *)(param_1 + 0x14) >> 8),
                   *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x4b)) + -1;
  bVar1 = (byte)iVar2;
  uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),bVar1 - 2);
  if (bVar1 < 2) {
    *param_3 = *param_3 + 0xc;
    return uVar3;
  }
  param_3[1] = param_3[1] + 0xc;
  return uVar3;
}

