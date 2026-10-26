/*
 * FUN_00436598 at 00436598
 * undefined __register FUN_00436598(int * param_1, int param_2, uint param_3)
 * Address ranges: 00436598-004365e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00436598(int *param_1,int param_2,uint param_3)

{
  short sVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined *)0x0;
  puStack_18 = &LAB_004365e2;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_00414028(param_2,(int *)&local_8,param_3);
  sVar1 = FUN_00435bd8(local_8);
  FUN_004380b8(param_1,sVar1);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004365e9;
  puStack_18 = (undefined1 *)0x4365e1;
  FUN_00403b50((int *)&local_8);
  return;
}

