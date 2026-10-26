/*
 * FUN_00457b4c at 00457b4c
 * undefined __register FUN_00457b4c(int param_1)
 * Address ranges: 00457b4c-00457c03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457b4c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_FS_OFFSET;
  int iStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined *local_18;
  int local_14 [2];
  undefined *local_c;
  int local_8;
  
  puStack_28 = &stack0xfffffffc;
  local_8 = 0;
  local_c = (undefined *)0x0;
  local_14[1] = 0;
  local_14[0] = 0;
  local_18 = (undefined *)0x0;
  puStack_2c = &LAB_00457c04;
  iStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_30;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = 0;
  do {
    FUN_00407f60(iVar2,local_14 + 1);
    FUN_00403e90(&local_8,3);
    FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
    FUN_004081c4(local_18,local_14);
    iStack_30 = local_8;
    FUN_00403e90((int *)&local_c,4);
    uVar1 = FUN_0040811c(local_c);
    if ((char)uVar1 == '\x01') {
      *(undefined1 *)(param_1 + 0xc + iVar2) = 1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x1e);
  *in_FS_OFFSET = iStack_30;
  FUN_00403b74((int *)&local_18,5);
  return;
}

