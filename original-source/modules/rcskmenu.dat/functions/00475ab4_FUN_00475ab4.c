/*
 * FUN_00475ab4 at 00475ab4
 * undefined __register FUN_00475ab4(int param_1)
 * Address ranges: 00475ab4-00475c3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475ab4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
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
  puStack_24 = &LAB_00475c3f;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  FUN_00475d6c(param_1);
  uVar1 = FUN_00457cac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),*(int *)(param_1 + 0x3a4));
  uVar2 = FUN_00457c88(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),*(int *)(param_1 + 0x3a4));
  if (-1 < (int)uVar1) {
    uVar3 = FUN_00475c50(param_1,uVar1);
    FUN_00403be8((int *)&local_8,*(int *)(&DAT_0047e488 + (uVar3 & 0x7f) * 4));
  }
  if (((int)uVar2 < 0x1e) && (-1 < (int)uVar2)) {
    uVar3 = FUN_00475c50(param_1,uVar2);
    FUN_00403be8((int *)&local_10,*(int *)(&DAT_0047e488 + (uVar3 & 0x7f) * 4));
  }
  iVar4 = FUN_00457c6c(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
  if (iVar4 < 0) {
    (**(code **)(**(int **)(param_1 + 0x398) + 0x5c))(*(int **)(param_1 + 0x398),0);
    (**(code **)(**(int **)(param_1 + 0x2e8) + 0x5c))(*(int **)(param_1 + 0x2e8),0);
  }
  else {
    FUN_00403be8((int *)&local_c,
                 *(int *)(&DAT_0047e478 + (uint)*(byte *)(*(int *)(param_1 + 0x3a8) + 0x22) * 4));
    (**(code **)(**(int **)(param_1 + 0x398) + 0x5c))(*(int **)(param_1 + 0x398),1);
    (**(code **)(**(int **)(param_1 + 0x2e8) + 0x5c))(*(int **)(param_1 + 0x2e8),1);
  }
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2f8) + 300),local_8);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2f4) + 300),local_c);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x2f0) + 300),local_10);
  (**(code **)(**(int **)(param_1 + 0x30c) + 0x5c))(*(int **)(param_1 + 0x30c),uVar2 < 0x80000000);
  (**(code **)(**(int **)(param_1 + 0x308) + 0x5c))(*(int **)(param_1 + 0x308),uVar1 < 0x80000000);
  FUN_0043fb28(*(int **)(param_1 + 0x30c));
  FUN_0043fb28(*(int **)(param_1 + 0x308));
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00475c46;
  puStack_24 = (undefined1 *)0x475c3e;
  FUN_00403b74((int *)&local_10,3);
  return;
}

