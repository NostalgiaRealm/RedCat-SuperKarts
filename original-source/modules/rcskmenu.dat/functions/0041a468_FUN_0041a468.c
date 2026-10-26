/*
 * FUN_0041a468 at 0041a468
 * undefined __register FUN_0041a468(int * param_1, undefined * param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 0041a468-0041a4ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a468(int *param_1,undefined *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_10 = (undefined4 *)0x0;
  puStack_24 = &LAB_0041a4eb;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_c = param_3;
  local_8 = param_2;
  puVar1 = FUN_004046fc(0x10,"\x0e\vTFileFormat\x10");
  FUN_00407d7c(local_8,(int *)&local_10);
  FUN_00403ba4(puVar1 + 1,local_10);
  *puVar1 = param_4;
  FUN_00403ba4(puVar1 + 2,local_c);
  puVar1[3] = param_5;
  FUN_0040f504(param_1,(int)puVar1);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0041a4f2;
  puStack_24 = (undefined1 *)0x41a4ea;
  FUN_00403b50((int *)&local_10);
  return;
}

