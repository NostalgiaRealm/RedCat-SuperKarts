/*
 * FUN_00457a30 at 00457a30
 * undefined __register FUN_00457a30(int param_1, int param_2)
 * Address ranges: 00457a30-00457ae8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457a30(int param_1,int param_2)

{
  undefined1 *puVar1;
  int *in_FS_OFFSET;
  int iStack_48;
  int iStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined *local_18;
  int local_14 [2];
  undefined4 *local_c;
  int local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_8 = 0;
  local_c = (undefined4 *)0x0;
  local_14[1] = 0;
  local_14[0] = 0;
  local_18 = (undefined *)0x0;
  puStack_28 = &LAB_00457ae9;
  iStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_2c;
  puVar1 = &stack0xfffffffc;
  if ((-1 < param_2) && (puVar1 = &stack0xfffffffc, param_2 < 0x1e)) {
    FUN_00407f60(param_2,local_14 + 1);
    FUN_00403e90(&local_8,3);
    FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
    FUN_004081c4(local_18,local_14);
    iStack_48 = local_8;
    FUN_00403e90((int *)&local_c,4);
    FUN_0045a5dc(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80),local_c);
    *(undefined1 *)(param_1 + 0xc + param_2) = 1;
    puVar1 = puStack_24;
  }
  puStack_24 = puVar1;
  *in_FS_OFFSET = iStack_48;
  FUN_00403b74((int *)&local_18,5);
  return;
}

