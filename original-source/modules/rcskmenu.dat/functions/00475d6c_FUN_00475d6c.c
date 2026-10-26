/*
 * FUN_00475d6c at 00475d6c
 * undefined __register FUN_00475d6c(int param_1)
 * Address ranges: 00475d6c-00475e81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475d6c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int *local_14;
  uint *local_10;
  byte local_9;
  int local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_10 = (uint *)0x0;
  puStack_24 = &LAB_00475e82;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_8 = param_1;
  FUN_004578f4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),*(int *)(param_1 + 0x3a4));
  FUN_0045792c(*(undefined4 *)(*(int *)PTR_DAT_0047c670 + 0x98),*(undefined4 *)(local_8 + 0x3a4));
  FUN_0045a030(*(int *)(local_8 + 0x3a8),*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
  FUN_0043f67c(*(int *)(local_8 + 0x304),*(uint **)(*(int *)(local_8 + 0x3a8) + 0xc));
  local_9 = 0;
  uVar3 = extraout_EDX;
  do {
    uVar4 = 0;
    piVar5 = &DAT_0047e498;
    local_14 = &DAT_0047e4ac;
    do {
      cVar1 = FUN_0045a9e8(*(int *)(local_8 + 0x3a8),CONCAT31((int3)((uint)uVar3 >> 8),local_9),
                           uVar4);
      if (cVar1 == '\x01') {
        FUN_00403be8((int *)&local_10,*piVar5);
      }
      else {
        FUN_00403be8((int *)&local_10,*local_14);
      }
      iVar2 = FUN_00475ef0(local_8,local_9,(char)uVar4);
      uVar3 = extraout_EDX_00;
      if (iVar2 != 0) {
        FUN_00452c0c(*(int *)(iVar2 + 300),local_10);
        uVar3 = extraout_EDX_01;
      }
      uVar4 = uVar4 + 1;
      local_14 = local_14 + 1;
      piVar5 = piVar5 + 1;
    } while ((char)uVar4 != '\x05');
    local_9 = local_9 + 1;
  } while (local_9 != 6);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00475e89;
  puStack_24 = (undefined1 *)0x475e81;
  FUN_00403b50((int *)&local_10);
  return;
}

