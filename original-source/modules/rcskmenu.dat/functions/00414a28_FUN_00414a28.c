/*
 * FUN_00414a28 at 00414a28
 * undefined __register FUN_00414a28(int param_1)
 * Address ranges: 00414a28-00414a60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414a28(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x20) & 8) == 0) {
    *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) | 8;
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 8), -1 < iVar2 + -1)) {
      iVar3 = 0;
      do {
        iVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x10),iVar3);
        FUN_00414a28(iVar1);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}

