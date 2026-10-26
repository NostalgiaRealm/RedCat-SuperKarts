/*
 * FUN_00473244 at 00473244
 * undefined __register FUN_00473244(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00473244-0047328d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473244(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  int *local_8;
  
  puStack_c = &stack0xfffffffc;
  puStack_10 = &LAB_0047328e;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  local_8 = (int *)param_3;
  local_8 = FUN_0045d414((int *)&PTR_FUN_00470dfc,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  (**(code **)(*local_8 + 0xd8))();
  *in_FS_OFFSET = uStack_14;
  puStack_c = &LAB_00473295;
  puStack_10 = (undefined1 *)0x47328d;
  FUN_00402eac(local_8);
  return;
}

