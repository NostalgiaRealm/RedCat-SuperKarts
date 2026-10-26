/*
 * FUN_0042a3d0 at 0042a3d0
 * undefined __register FUN_0042a3d0(int param_1)
 * Address ranges: 0042a3d0-0042a4e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a3d0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(char *)(param_1 + 0x1c) != '\0') {
    iVar1 = FUN_00429ce4(param_1);
    iVar1 = *(int *)(param_1 + 0x10) - iVar1;
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 < 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
  }
  FUN_00429ce4(param_1);
  FUN_0042a2c8();
  *(undefined1 *)(param_1 + 0x44) = 0;
  FUN_00445724(*(int **)(param_1 + 4));
  (**(code **)PTR_DAT_0047c85c)();
  FUN_0042a14c(param_1,*(int *)(param_1 + 0xc));
  iVar1 = FUN_00429ce4(param_1);
  uVar2 = (iVar1 * 9) / 10;
  *(short *)(param_1 + 10) = (short)uVar2;
  if (*(char *)(param_1 + 0x1f) != '\0') {
    *(short *)(param_1 + 8) = (short)((ulonglong)(uVar2 & 0xffff) / 10);
  }
  return;
}

