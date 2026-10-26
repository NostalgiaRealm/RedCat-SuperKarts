/*
 * FUN_00476eb8 at 00476eb8
 * undefined __register FUN_00476eb8(int param_1)
 * Address ranges: 00476eb8-00476fdd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00476eb8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  uint *local_20;
  undefined1 local_1c [4];
  uint *local_18;
  byte local_14;
  int local_c;
  byte local_8;
  
  local_20 = (uint *)0x0;
  puStack_30 = (undefined1 *)0x476ed6;
  FUN_00404300((int)local_1c,(int)&DAT_004584ec);
  puStack_34 = &LAB_00476fde;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  FUN_004585e4(*(int *)(param_1 + 0x380),
               *(int *)(PTR_PTR_0047c804 + (uint)*(byte *)(param_1 + 900) * 4));
  iVar2 = 0;
  do {
    FUN_00458afc(*(int *)(param_1 + 0x380),iVar2,(int)local_1c);
    iVar1 = FUN_00477030(param_1,(undefined4 *)"imgHigh",iVar2 + 1);
    if (iVar1 != 0) {
      FUN_00452c0c(*(int *)(iVar1 + 300),*(uint **)(&DAT_0047e524 + (local_14 & 0x7f) * 4));
    }
    iVar1 = FUN_00477104(param_1,(undefined4 *)"lblName",iVar2 + 1);
    if (iVar1 != 0) {
      FUN_0043f67c(iVar1,local_18);
    }
    iVar1 = FUN_00477104(param_1,(undefined4 *)"lblRound",iVar2 + 1);
    if (iVar1 != 0) {
      FUN_0045c910(local_c,(int *)&local_20);
      FUN_0043f67c(iVar1,local_20);
    }
    iVar1 = FUN_00477104(param_1,(undefined4 *)"lblDiff",iVar2 + 1);
    if (iVar1 != 0) {
      FUN_0043f67c(iVar1,*(uint **)(PTR_PTR_0047c67c + (uint)local_8 * 4));
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_00476fe5;
  puStack_34 = (undefined1 *)0x476fcf;
  FUN_00403b50((int *)&local_20);
  puStack_34 = (undefined1 *)0x476fdd;
  FUN_004043cc((int)local_1c,(int)&DAT_004584ec);
  return;
}

