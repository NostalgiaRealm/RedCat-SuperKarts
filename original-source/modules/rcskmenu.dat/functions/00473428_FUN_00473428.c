/*
 * FUN_00473428 at 00473428
 * undefined __register FUN_00473428(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00473428-0047349f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473428(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *local_c;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (uint *)0x0;
  puStack_18 = &LAB_004734a0;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if (*(int *)(param_1 + 0x330) < 1) {
    FUN_00473244(param_1,param_2,param_3);
  }
  else {
    puStack_14 = &stack0xfffffffc;
    FUN_0045c4c8(0x4a,(int *)&local_8);
    puVar1 = local_8;
    FUN_0045c4f0(0x18,(int *)&local_c);
    FUN_00460df0(local_c,puVar1,4);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004734a7;
  puStack_18 = (undefined1 *)0x47349f;
  FUN_00403b74((int *)&local_c,2);
  return;
}

