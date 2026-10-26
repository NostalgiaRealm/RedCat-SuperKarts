/*
 * FUN_00471c70 at 00471c70
 * undefined __register FUN_00471c70(int param_1, int param_2)
 * Address ranges: 00471c70-00471dd7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471c70(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined1 local_28 [4];
  int local_24;
  undefined1 local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 local_14;
  undefined4 *local_10;
  undefined1 local_9;
  int local_8;
  
  local_10 = (undefined4 *)0x0;
  puStack_38 = (undefined1 *)0x471c91;
  local_8 = param_2;
  FUN_00404300((int)local_28,(int)&DAT_004584ec);
  puStack_3c = &LAB_00471dd8;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_38 = &stack0xfffffffc;
  piVar1 = FUN_00458584((int *)&DAT_00458564,'\x01',extraout_ECX);
  if (piVar1 == (int *)0x0) {
    local_9 = 0;
  }
  else {
    FUN_004585e4((int)piVar1,
                 *(int *)(PTR_PTR_0047c804 +
                         (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x25) * 4));
    iVar2 = FUN_00458a00((int)piVar1,local_8);
    if (iVar2 < 0) {
      local_9 = 0;
    }
    else {
      FUN_0045c5cc(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),0x24);
      FUN_00471dec(param_1,iVar2,(int *)&local_10);
      if (local_10 == (undefined4 *)0x0) {
        local_9 = 0;
        goto LAB_00471db4;
      }
      FUN_00403ba4((int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0xc),local_10);
      FUN_00403be8(&local_24,(int)local_10);
      local_1c = *(undefined4 *)(param_1 + 0x334);
      local_20 = *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22);
      local_18 = local_8;
      local_14 = FUN_0045a9e0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
      FUN_00458a40((int)piVar1,iVar2,(int)local_28);
      local_9 = 1;
    }
    FUN_00458838((int)piVar1,
                 *(int *)(PTR_PTR_0047c804 +
                         (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x25) * 4));
    FUN_00402eac(piVar1);
  }
LAB_00471db4:
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_00471ddf;
  puStack_3c = (undefined1 *)0x471dcf;
  FUN_004043cc((int)local_28,(int)&DAT_004584ec);
  puStack_3c = (undefined1 *)0x471dd7;
  FUN_00403b50((int *)&local_10);
  return;
}

