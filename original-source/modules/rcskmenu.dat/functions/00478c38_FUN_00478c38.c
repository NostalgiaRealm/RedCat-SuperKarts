/*
 * FUN_00478c38 at 00478c38
 * undefined __register FUN_00478c38(int param_1)
 * Address ranges: 00478c38-00478ce6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478c38(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
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
  uVar3 = 0;
  local_10 = (uint *)0x0;
  puStack_24 = &LAB_00478ce7;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_9 = 0;
  local_8 = param_1;
  do {
    uVar4 = 0;
    piVar5 = &DAT_0047e568;
    local_14 = &DAT_0047e57c;
    do {
      cVar1 = FUN_0045a9e8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80),
                           CONCAT31((int3)((uint)uVar3 >> 8),local_9),uVar4);
      if (cVar1 == '\x01') {
        FUN_00403be8((int *)&local_10,*piVar5);
      }
      else {
        FUN_00403be8((int *)&local_10,*local_14);
      }
      iVar2 = FUN_00478cf4(local_8,local_9,(char)uVar4);
      uVar3 = extraout_EDX;
      if (iVar2 != 0) {
        FUN_00452c0c(*(int *)(iVar2 + 300),local_10);
        uVar3 = extraout_EDX_00;
      }
      uVar4 = uVar4 + 1;
      local_14 = local_14 + 1;
      piVar5 = piVar5 + 1;
    } while ((char)uVar4 != '\x05');
    local_9 = local_9 + 1;
  } while (local_9 != 6);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00478cee;
  puStack_24 = (undefined1 *)0x478ce6;
  FUN_00403b50((int *)&local_10);
  return;
}

