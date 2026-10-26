/*
 * FUN_0045792c at 0045792c
 * undefined __register FUN_0045792c(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0045792c-004579e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045792c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *in_FS_OFFSET;
  int iStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined *local_18;
  int local_14 [2];
  undefined4 *local_c;
  int local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_8 = 0;
  local_c = (undefined4 *)0x0;
  local_14[1] = 0;
  local_14[0] = 0;
  local_18 = (undefined *)0x0;
  puStack_24 = &LAB_004579e4;
  iStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_28;
  FUN_00407f60(param_2,local_14 + 1);
  FUN_00403e90(&local_8,3);
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
  FUN_004081c4(local_18,local_14);
  iVar1 = local_8;
  FUN_00403e90((int *)&local_c,4);
  uVar2 = FUN_0040811c((undefined *)local_c);
  if ((char)uVar2 != '\0') {
    FUN_0045a3c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80),local_c);
  }
  *in_FS_OFFSET = iVar1;
  FUN_00403b74((int *)&local_18,5);
  return;
}

