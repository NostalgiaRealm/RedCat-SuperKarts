/*
 * FUN_0043f67c at 0043f67c
 * undefined __register FUN_0043f67c(int param_1, uint * param_2)
 * Address ranges: 0043f67c-0043f6d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f67c(int param_1,uint *param_2)

{
  undefined *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar2;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  uVar2 = 1;
  puStack_18 = &LAB_0043f6d1;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0043f64c(param_1,(int *)&local_8);
  FUN_00403ee0(local_8,param_2);
  if (!(bool)uVar2) {
    puVar1 = FUN_00403f94((undefined *)param_2);
    FUN_0043f628(param_1,puVar1);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0043f6d8;
  puStack_18 = (undefined1 *)0x43f6d0;
  FUN_00403b50((int *)&local_8);
  return;
}

