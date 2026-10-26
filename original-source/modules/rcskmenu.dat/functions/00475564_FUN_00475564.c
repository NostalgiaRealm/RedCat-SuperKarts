/*
 * FUN_00475564 at 00475564
 * undefined __register FUN_00475564(int * param_1)
 * Address ranges: 00475564-0047565d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475564(int *param_1)

{
  undefined1 *puVar1;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  char unaff_BL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_0047565e;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puVar1 = &stack0xfffffffc;
  if (*(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98) + 8) == 0) {
    FUN_0045c4c8(0x31,(int *)&local_8);
    FUN_00460d08(local_8);
    unaff_BL = FUN_004760c0(param_1);
    puVar1 = puStack_14;
    if (unaff_BL == '\0') goto LAB_00475648;
  }
  puStack_14 = puVar1;
  FUN_004578f4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98),param_1[0xe9]);
  iVar2 = param_1[0xe9];
  *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x14) = iVar2;
  FUN_00475674((int)param_1,iVar2,extraout_ECX);
  iVar2 = extraout_ECX_00;
  uVar3 = extraout_EDX;
  if (*(char *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x26) == '\x01') {
    FUN_0045a184(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
    FUN_00457b34(*(int *)(*(int *)PTR_DAT_0047c670 + 0x98));
    iVar2 = extraout_ECX_01;
    uVar3 = extraout_EDX_00;
  }
  if (unaff_BL == '\x01') {
    *(undefined1 *)(param_1 + 0xb5) = 8;
  }
  else {
    FUN_0045c518(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),0x11,1);
    *(undefined1 *)(param_1 + 0xb5) = 1;
    iVar2 = extraout_ECX_02;
    uVar3 = extraout_EDX_01;
  }
  FUN_0042eb18(param_1,uVar3,iVar2);
LAB_00475648:
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00475665;
  puStack_18 = (undefined1 *)0x47565d;
  FUN_00403b50((int *)&local_8);
  return;
}

