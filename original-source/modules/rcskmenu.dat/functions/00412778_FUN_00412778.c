/*
 * FUN_00412778 at 00412778
 * undefined __register FUN_00412778(int * param_1)
 * Address ranges: 00412778-0041286e;00412876-0041288b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412778(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_10;
  char *local_c;
  int *local_8;
  
  puStack_20 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  local_c = (char *)0x0;
  puStack_24 = &LAB_0041288c;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  iVar5 = param_1[0xc];
  local_8 = param_1;
  if (iVar5 == 0) {
    *in_FS_OFFSET = uStack_28;
    puStack_20 = &LAB_00412893;
    puStack_24 = (undefined1 *)0x41288b;
    FUN_00403b50((int *)&local_c);
    return;
  }
  puStack_30 = &LAB_0041286f;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  local_10 = *(int *)(iVar5 + 8);
  if (-1 < local_10 + -1) {
    iVar5 = 0;
    puStack_20 = &stack0xfffffffc;
    do {
      iVar2 = FUN_0040f6b0((undefined4 *)local_8[0xc],iVar5);
      FUN_00403be8((int *)&local_c,*(int *)(iVar2 + 0x14));
      (**(code **)(*local_8 + 0x20))(local_8,&local_c);
      iVar3 = FUN_00412074(*(int *)(iVar2 + 8),local_c);
      iVar4 = FUN_0040f6b0((undefined4 *)local_8[0xc],iVar5);
      FUN_004126fc(iVar4);
      if (iVar3 == 0) {
        bVar1 = FUN_0041202c(iVar2);
        if (!bVar1) goto LAB_00412842;
        iVar2 = FUN_0040f6b0((undefined4 *)local_8[0xc],iVar5);
        FUN_0040f9e8(DAT_0047d630,iVar2);
        FUN_0040f7fc((int *)local_8[0xc],iVar5,0);
      }
      else {
LAB_00412842:
        FUN_0040d3f4(*(int **)(iVar2 + 4),*(undefined4 **)(iVar2 + 0xc),iVar3);
      }
      iVar5 = iVar5 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  *in_FS_OFFSET = uStack_34;
  puStack_2c = (undefined1 *)0x412876;
  puStack_30 = (undefined1 *)0x41286e;
  FUN_004128bc((int)local_8);
  return;
}

