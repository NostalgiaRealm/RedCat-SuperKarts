/*
 * FUN_0043aa14 at 0043aa14
 * undefined __register FUN_0043aa14(undefined4 * param_1, undefined4 * param_2)
 * Address ranges: 0043aa14-0043aa6c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043aa14(undefined4 *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined *local_c;
  undefined *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (undefined *)0x0;
  local_c = (undefined *)0x0;
  puStack_1c = &LAB_0043aa6d;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_0043a918(param_2,(int *)&local_8);
  puVar1 = local_8;
  FUN_0043a918(param_1,(int *)&local_c);
  FUN_00407de8(local_c,puVar1);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0043aa74;
  puStack_1c = (undefined1 *)0x43aa6c;
  FUN_00403b74((int *)&local_c,2);
  return;
}

