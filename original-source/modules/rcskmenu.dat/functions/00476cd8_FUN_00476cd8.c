/*
 * FUN_00476cd8 at 00476cd8
 * undefined __register FUN_00476cd8(int param_1, undefined4 param_2)
 * Address ranges: 00476cd8-00476eaa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00476cd8(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  char cVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 unaff_EBX;
  undefined3 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  puStack_20 = &LAB_00476eab;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  uVar3 = (undefined3)((uint)unaff_EBX >> 8);
  puVar1 = &stack0xfffffffc;
  if (*(char *)(param_1 + 900) != '\0') {
    cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                         CONCAT31(uVar3,*(char *)(param_1 + 900)) - 1);
    if (cVar2 == '\0') {
      FUN_00403be8((int *)&local_8,*(int *)(&DAT_0047e4b8 + (uint)*(byte *)(param_1 + 900) * 0x10));
      param_2 = extraout_EDX_00;
      puVar1 = puStack_1c;
    }
    else {
      FUN_00403be8((int *)&local_8,*(int *)(&DAT_0047e4c0 + (uint)*(byte *)(param_1 + 900) * 0x10));
      param_2 = extraout_EDX;
      puVar1 = puStack_1c;
    }
  }
  puStack_1c = puVar1;
  cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                       CONCAT31((int3)((uint)param_2 >> 8),*(undefined1 *)(param_1 + 900)));
  if (cVar2 == '\0') {
    FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047e4c4 + (uint)*(byte *)(param_1 + 900) * 0x10));
  }
  else {
    FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047e4cc + (uint)*(byte *)(param_1 + 900) * 0x10));
  }
  if (*(byte *)(param_1 + 900) < 5) {
    cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                         CONCAT31(uVar3,*(byte *)(param_1 + 900)) + 1);
    if (cVar2 == '\0') {
      FUN_00403be8((int *)&local_10,*(int *)(&DAT_0047e4d8 + (uint)*(byte *)(param_1 + 900) * 0x10))
      ;
    }
    else {
      FUN_00403be8((int *)&local_10,*(int *)(&DAT_0047e4e0 + (uint)*(byte *)(param_1 + 900) * 0x10))
      ;
    }
  }
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x32c) + 300),local_8);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x324) + 300),local_10);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x328) + 300),local_c);
  (**(code **)(**(int **)(param_1 + 0x340) + 0x5c))
            (*(int **)(param_1 + 0x340),
             CONCAT31((int3)((uint)extraout_EDX_01 >> 8),*(char *)(param_1 + 900) == '\x05') ^ 1);
  (**(code **)(**(int **)(param_1 + 0x33c) + 0x5c))
            (*(int **)(param_1 + 0x33c),
             CONCAT31((int3)((uint)extraout_EDX_02 >> 8),*(char *)(param_1 + 900) == '\0') ^ 1);
  FUN_0043f67c(*(int *)(param_1 + 0x338),
               *(uint **)(PTR_PTR_0047c804 + (uint)*(byte *)(param_1 + 900) * 4));
  FUN_0043fb28(*(int **)(param_1 + 0x340));
  FUN_0043fb28(*(int **)(param_1 + 0x33c));
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00476eb2;
  puStack_20 = (undefined1 *)0x476eaa;
  FUN_00403b74((int *)&local_10,3);
  return;
}

