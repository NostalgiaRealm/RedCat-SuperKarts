/*
 * FUN_0043ed90 at 0043ed90
 * undefined __register FUN_0043ed90(int param_1)
 * Address ranges: 0043ed90-0043ee64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043ed90(int param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_18 [8];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (((*(char *)(param_1 + 0x52) == '\0') && ((*(byte *)(param_1 + 0x20) & 1) == 0)) &&
     (bVar1 = *(byte *)(param_1 + 0x51), bVar1 != 3)) {
    if ((bVar1 & 4) == 0) {
      iVar3 = (int)*(uint *)(param_1 + 0x38) >> 1;
      if (iVar3 < 0) {
        iVar3 = iVar3 + (uint)((*(uint *)(param_1 + 0x38) & 1) != 0);
      }
      *(int *)(param_1 + 0x78) = iVar3 + *(int *)(param_1 + 0x30);
    }
    else if ((bVar1 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x30);
    }
    else {
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x38);
    }
    if ((bVar1 & 8) == 0) {
      iVar3 = (int)*(uint *)(param_1 + 0x3c) >> 1;
      if (iVar3 < 0) {
        iVar3 = iVar3 + (uint)((*(uint *)(param_1 + 0x3c) & 1) != 0);
      }
      *(int *)(param_1 + 0x7c) = iVar3 + *(int *)(param_1 + 0x34);
    }
    else if ((bVar1 & 2) == 0) {
      *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x34);
    }
    else {
      *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x3c);
    }
    iVar3 = *(int *)(param_1 + 0x24);
    if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0x20) & 2) == 0)) {
      bVar2 = FUN_00445a20(iVar3);
      if (bVar2) {
        (**(code **)(**(int **)(param_1 + 0x24) + 0x40))(*(int **)(param_1 + 0x24),auStack_18);
        *(undefined4 *)(param_1 + 0x80) = uStack_10;
        *(undefined4 *)(param_1 + 0x84) = uStack_c;
      }
      else {
        *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x38);
        *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x3c);
      }
    }
  }
  return;
}

