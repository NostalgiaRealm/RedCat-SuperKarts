/*
 * FUN_00454d60 at 00454d60
 * undefined __register FUN_00454d60(int param_1, undefined4 param_2, undefined4 * param_3)
 * Address ranges: 00454d60-00454db4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454d60(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 *puVar2;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_8;
  
  puStack_14 = (undefined1 *)0x454d75;
  local_8 = param_3;
  FUN_00403f84((int)param_3);
  puStack_18 = &LAB_00454db5;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puVar2 = local_8;
  puStack_14 = &stack0xfffffffc;
  iVar1 = FUN_00454c18((int *)&DAT_00454b88,'\x01',param_2,local_8);
  FUN_0040f504(*(int **)(param_1 + 8),iVar1);
  *in_FS_OFFSET = puVar2;
  puStack_18 = &LAB_00454dbc;
  uStack_1c = 0x454db4;
  FUN_00403b50((int *)&local_8);
  return;
}

