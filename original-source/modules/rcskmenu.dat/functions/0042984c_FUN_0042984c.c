/*
 * FUN_0042984c at 0042984c
 * undefined __register FUN_0042984c(undefined4 param_1, int param_2)
 * Address ranges: 0042984c-004298a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042984c(undefined4 param_1,int param_2)

{
  char *pcVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  char *local_c;
  char *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (char *)0x0;
  local_c = (char *)0x0;
  puStack_1c = &LAB_004298aa;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_0043a9b0(param_2,(int *)&local_8);
  pcVar1 = local_8;
  FUN_00403cf8((int *)&local_c,param_1);
  FUN_00407d04(local_c,pcVar1);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_004298b1;
  puStack_1c = (undefined1 *)0x4298a9;
  FUN_00403b74((int *)&local_c,2);
  return;
}

