/*
 * FUN_004740f8 at 004740f8
 * undefined __register FUN_004740f8(int param_1)
 * Address ranges: 004740f8-00474223
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004740f8(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX_01;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_10;
  uint *local_c;
  uint *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  local_10 = (uint *)0x0;
  puStack_24 = &LAB_00474224;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  bVar1 = *(byte *)(param_1 + 0x338);
  puVar2 = &stack0xfffffffc;
  if (bVar1 != 0) {
    FUN_00403be8((int *)&local_8,*(int *)(&DAT_0047e458 + (uint)bVar1 * 4));
    puVar2 = puStack_20;
  }
  puStack_20 = puVar2;
  FUN_00403be8((int *)&local_c,*(int *)(&DAT_0047e44c + (bVar1 & 0x7f) * 4));
  uVar3 = extraout_EDX;
  if (bVar1 < 3) {
    FUN_00403be8((int *)&local_10,*(int *)(&DAT_0047e460 + (bVar1 & 0x7f) * 4));
    uVar3 = extraout_EDX_00;
  }
  (**(code **)(**(int **)(param_1 + 0x2f8) + 0x5c))
            (*(int **)(param_1 + 0x2f8),CONCAT31((int3)((uint)uVar3 >> 8),bVar1 == 3) ^ 1);
  (**(code **)(**(int **)(param_1 + 0x2fc) + 0x5c))
            (*(int **)(param_1 + 0x2fc),
             CONCAT31((int3)((uint)extraout_EDX_01 >> 8),*(char *)(param_1 + 0x338) == '\0') ^ 1);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x308) + 300),local_8);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x30c) + 300),local_c);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x310) + 300),local_10);
  FUN_0043f67c(*(int *)(param_1 + 0x31c),
               *(uint **)(PTR_PTR_0047c5e0 + (uint)*(byte *)(param_1 + 0x338) * 4));
  FUN_0043fb28(*(int **)(param_1 + 0x2f8));
  FUN_0043fb28(*(int **)(param_1 + 0x2fc));
  *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22) =
       *(undefined1 *)(param_1 + 0x338);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0047422b;
  puStack_24 = (undefined1 *)0x474223;
  FUN_00403b74((int *)&local_10,3);
  return;
}

