/*
 * TDataModule1_defRadiobuttonGetCaptionRect at 0045cd98
 * undefined TDataModule1_defRadiobuttonGetCaptionRect(void)
 * Address ranges: 0045cd98-0045ce04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TDataModule1_defRadiobuttonGetCaptionRect; original record 0005b31f
 */

/* Named by original Delphi published-method table: TDataModule1_defRadiobuttonGetCaptionRect;
   original record 0005b31f */

void TDataModule1_defRadiobuttonGetCaptionRect
               (undefined4 param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00452e7c);
  if ((char)uVar1 == '\0') {
    FUN_00403b34("Assertion failure");
  }
  iVar2 = FUN_0040303c(param_2,(int)&PTR_FUN_00452e7c);
  uVar4 = *(int *)(iVar2 + 0x48) - 0x26;
  iVar5 = (int)uVar4 >> 1;
  if (iVar5 < 0) {
    iVar5 = iVar5 + (uint)((uVar4 & 1) != 0);
  }
  uVar4 = *(int *)(iVar2 + 0x44) - 0x3c;
  iVar3 = (int)uVar4 >> 1;
  if (iVar3 < 0) {
    iVar3 = iVar3 + (uint)((uVar4 & 1) != 0);
  }
  FUN_0040ebe8(iVar3,iVar5,*(int *)(iVar2 + 0x44),param_4,*(int *)(iVar2 + 0x48));
  return;
}

