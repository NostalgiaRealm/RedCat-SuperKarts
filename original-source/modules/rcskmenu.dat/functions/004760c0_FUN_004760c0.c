/*
 * FUN_004760c0 at 004760c0
 * undefined __register FUN_004760c0(int * param_1)
 * Address ranges: 004760c0-004761d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004760c0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (uint *)0x0;
  puStack_24 = &LAB_004761d2;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  iVar3 = FUN_00457c50(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
  if (iVar3 < 0) {
    FUN_0045c4c8(0x34,(int *)&local_c);
    puVar2 = local_c;
    FUN_0045c4f0(0x15,(int *)&local_10);
    FUN_00460df0(local_10,puVar2,4);
  }
  else {
    FUN_004761e8(param_1,iVar3,(int *)&local_8);
    if (local_8 != (undefined4 *)0x0) {
      FUN_0045aa5c(param_1[0xea]);
      FUN_00403ba4((int *)(param_1[0xea] + 0xc),local_8);
      FUN_00475674((int)param_1,extraout_EDX,extraout_ECX);
      FUN_004578f4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),iVar3);
      FUN_00457b34(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
      piVar1 = (int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98) + 8);
      *piVar1 = *piVar1 + 1;
      *(undefined1 *)(param_1 + 0xeb) = 1;
      *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x14) = iVar3;
      *(undefined1 *)(param_1 + 0xb5) = 8;
      FUN_0042eb18(param_1,extraout_EDX_00,extraout_ECX_00);
    }
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_004761d9;
  puStack_24 = (undefined1 *)0x4761d1;
  FUN_00403b74((int *)&local_10,3);
  return;
}

