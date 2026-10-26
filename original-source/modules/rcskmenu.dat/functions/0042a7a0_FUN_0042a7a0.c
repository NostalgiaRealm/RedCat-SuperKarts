/*
 * FUN_0042a7a0 at 0042a7a0
 * undefined __register FUN_0042a7a0(int param_1)
 * Address ranges: 0042a7a0-0042a88a;0042a892-0042a894
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a7a0(int param_1)

{
  bool bVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  int local_8;
  
  if (*(char *)(param_1 + 0x200) == '\0') {
    puStack_c = (undefined1 *)0x42a7bf;
    local_8 = param_1;
    bVar1 = FUN_00445a20(param_1);
    if (bVar1) {
      puStack_10 = &LAB_0042a88b;
      uStack_14 = *in_FS_OFFSET;
      *in_FS_OFFSET = &uStack_14;
      *(undefined1 *)(local_8 + 0x200) = 1;
      puStack_c = &stack0xfffffffc;
      bVar1 = FUN_00429d64(*(int *)(local_8 + 500));
      if (bVar1) {
        FUN_0042a3d0(*(int *)(local_8 + 0x1f0));
        FUN_0042a3d0(*(int *)(local_8 + 500));
      }
      else {
        bVar1 = FUN_00429d64(*(int *)(local_8 + 0x1f0));
        if (bVar1) {
          FUN_0042a3d0(*(int *)(local_8 + 500));
          FUN_0042a3d0(*(int *)(local_8 + 0x1f0));
        }
        else {
          FUN_0042a3d0(*(int *)(local_8 + 500));
          FUN_0042a3d0(*(int *)(local_8 + 0x1f0));
        }
      }
      *in_FS_OFFSET = uStack_14;
      *(undefined1 *)(local_8 + 0x200) = 0;
      return;
    }
  }
  return;
}

