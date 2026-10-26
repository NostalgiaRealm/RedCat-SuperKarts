/*
 * FUN_00417594 at 00417594
 * undefined FUN_00417594(void)
 * Address ranges: 00417594-00417631;00417656-00417665
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417594(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x4175af;
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00415fdc);
  if ((char)uVar1 != '\0') {
    puStack_14 = (undefined1 *)0x4175bf;
    FUN_00417254((int)param_1);
    puStack_18 = &LAB_0041764f;
    uStack_1c = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_1c;
    puStack_20 = (undefined1 *)0x4175d7;
    puStack_14 = &stack0xfffffffc;
    FUN_00417254((int)param_2);
    puStack_24 = &LAB_00417632;
    uStack_28 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_28;
    puStack_20 = &stack0xfffffffc;
    FUN_00416d34(DAT_0047d6c8,param_1,(undefined4 *)param_2[4]);
    FUN_004176d0(param_1,param_2[6],extraout_ECX);
    if (param_1[7] != param_2[7]) {
      iVar2 = FUN_00417954((int)param_2);
      FUN_00417970(param_1,iVar2);
    }
    *in_FS_OFFSET = uStack_28;
    puStack_20 = &LAB_00417639;
    puStack_24 = (undefined1 *)0x417631;
    FUN_00417264((int)param_2);
    return;
  }
  puStack_14 = (undefined1 *)0x417661;
  FUN_0040fca8(param_1,param_2);
  return;
}

