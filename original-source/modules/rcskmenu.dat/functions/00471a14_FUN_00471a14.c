/*
 * FUN_00471a14 at 00471a14
 * undefined __register FUN_00471a14(int param_1)
 * Address ranges: 00471a14-00471a97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471a14(int param_1)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *local_c;
  uint *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  puStack_18 = &LAB_00471a98;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x01') {
    FUN_0045c4f0(0x1a,(int *)&local_8);
    FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2d8) + 300),local_8);
  }
  else {
    FUN_0045c4f0(0x1b,(int *)&local_c);
    FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2d8) + 300),local_c);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00471a9f;
  puStack_18 = (undefined1 *)0x471a97;
  FUN_00403b74((int *)&local_c,2);
  return;
}

