/*
 * FUN_004626e8 at 004626e8
 * undefined FUN_004626e8(void)
 * Address ranges: 004626e8-00462851
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004626e8(int *param_1,int *param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined1 *puStack_11c;
  int iStack_10c;
  byte abStack_108 [256];
  int iStack_8;
  
  puStack_11c = &stack0xfffffffc;
  iStack_10c = 0;
  iStack_8 = 0;
  puStack_120 = &LAB_00462852;
  uStack_124 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_124;
  puVar1 = &stack0xfffffffc;
  if (param_2 == (int *)0x0) {
    FUN_00402df8(*param_1,abStack_108);
    FUN_00403d74(&iStack_8,abStack_108);
    FUN_00403dd8(&iStack_8,(undefined4 *)".Assign: aSource not assigned.");
    FUN_00403b34(iStack_8);
    puVar1 = puStack_11c;
  }
  puStack_11c = puVar1;
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_004623a8);
  if ((char)uVar2 == '\0') {
    FUN_00402df8(*param_1,abStack_108);
    FUN_00403d74(&iStack_10c,abStack_108);
    FUN_00403dd8(&iStack_10c,(undefined4 *)".Assign: aSource not a TDaviColors.");
    FUN_00403b34(iStack_10c);
  }
  iVar3 = FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[2] = *(int *)(iVar3 + 8);
  FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[3] = *(int *)(iVar3 + 0xc);
  FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[4] = *(int *)(iVar3 + 0x10);
  FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[5] = *(int *)(iVar3 + 0x14);
  FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[6] = *(int *)(iVar3 + 0x18);
  FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[7] = *(int *)(iVar3 + 0x1c);
  FUN_0040303c(param_2,(int)&PTR_FUN_004623a8);
  param_1[8] = *(int *)(iVar3 + 0x20);
  FUN_0046263c((int)param_1);
  *in_FS_OFFSET = uStack_124;
  puStack_11c = &LAB_00462859;
  puStack_120 = (undefined1 *)0x462849;
  FUN_00403b50(&iStack_10c);
  puStack_120 = (undefined1 *)0x462851;
  FUN_00403b50(&iStack_8);
  return;
}

