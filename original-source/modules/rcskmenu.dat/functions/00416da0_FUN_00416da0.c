/*
 * FUN_00416da0 at 00416da0
 * undefined __register FUN_00416da0(int param_1)
 * Address ranges: 00416da0-00416dfe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00416da0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x416db1;
  FUN_00416b10(param_1);
  puStack_18 = &LAB_00416dff;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_14 = &stack0xfffffffc;
  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if (((HGDIOBJ)puVar1[2] != (HGDIOBJ)0x0) && ((int)puVar1[5] < 0)) {
      DeleteObject((HGDIOBJ)puVar1[2]);
      puVar1[2] = 0;
    }
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00416e06;
  puStack_18 = (undefined1 *)0x416dfe;
  FUN_00416b1c(param_1);
  return;
}

