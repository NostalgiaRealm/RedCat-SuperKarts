/*
 * FUN_00455f00 at 00455f00
 * undefined __register FUN_00455f00(int param_1, uint * param_2)
 * Address ranges: 00455f00-00455f6a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455f00(int param_1,uint *param_2)

{
  undefined4 *in_FS_OFFSET;
  bool bVar1;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  uint *local_8;
  
  puStack_10 = (undefined1 *)0x455f12;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  bVar1 = true;
  puStack_14 = &LAB_00455f6b;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  FUN_00403ee0(*(uint **)(param_1 + 0x24),local_8);
  if (!bVar1) {
    FUN_00403ba4((int *)(param_1 + 0x24),local_8);
    if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
      FUN_00455fb8(param_1);
      if (local_8 != (uint *)0x0) {
        FUN_004560b4(param_1,(undefined *)local_8);
      }
    }
  }
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00455f72;
  puStack_14 = (undefined1 *)0x455f6a;
  FUN_00403b50((int *)&local_8);
  return;
}

