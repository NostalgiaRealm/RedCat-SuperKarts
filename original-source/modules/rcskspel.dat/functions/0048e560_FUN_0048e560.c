/*
 * FUN_0048e560 at 0048e560
 * undefined FUN_0048e560(void)
 * Address ranges: 0048e560-0048e62a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_0048e560(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x380);
  if ((int)uVar1 < 0x20) {
    *(undefined4 *)(param_1 + uVar1 * 0x1c) = param_3;
    *(undefined4 *)(param_1 + 4 + *(int *)(param_1 + 0x380) * 0x1c) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x11 + *(int *)(param_1 + 0x380) * 0x1c) = 0;
    *(undefined4 *)(param_1 + 0xc + *(int *)(param_1 + 0x380) * 0x1c) = 0;
    *(undefined1 *)(param_1 + 0x10 + *(int *)(param_1 + 0x380) * 0x1c) = 0;
    *(undefined4 *)(param_1 + 8 + *(int *)(param_1 + 0x380) * 0x1c) = 0;
    *(undefined1 *)(param_1 + 0x12 + *(int *)(param_1 + 0x380) * 0x1c) = param_2;
    *(undefined4 *)(param_1 + 0x14 + *(int *)(param_1 + 0x380) * 0x1c) = param_4;
    iVar2 = *(int *)(param_1 + 0x380) + 1;
    *(int *)(param_1 + 0x380) = iVar2;
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}

