/*
 * FUN_00439954 at 00439954
 * undefined __register FUN_00439954(int * param_1)
 * Address ranges: 00439954-004399c3;004399cb-004399ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439954(int *param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  undefined1 local_a;
  char local_9;
  int *local_8;
  
  puStack_10 = &stack0xfffffffc;
  if (PTR_DAT_0047c9d8[9] != '\0') {
    local_9 = (char)param_1[9];
    local_a = *(undefined1 *)((int)param_1 + 0x35);
    puStack_14 = &LAB_004399c4;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    local_8 = param_1;
    if (local_9 == '\0') {
      puStack_10 = &stack0xfffffffc;
      FUN_00439e64(param_1,'\x01');
    }
    else {
      FUN_00439e64(param_1,'\0');
    }
    *in_FS_OFFSET = uStack_18;
    puStack_10 = (undefined1 *)0x4399cb;
    puStack_14 = (undefined1 *)0x4399ba;
    FUN_00439e64(local_8,local_9);
    *(undefined1 *)((int)local_8 + 0x35) = local_a;
    return;
  }
  return;
}

