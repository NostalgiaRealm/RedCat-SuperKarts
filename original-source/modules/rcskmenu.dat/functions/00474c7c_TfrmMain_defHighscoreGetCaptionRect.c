/*
 * TfrmMain_defHighscoreGetCaptionRect at 00474c7c
 * undefined TfrmMain_defHighscoreGetCaptionRect(void)
 * Address ranges: 00474c7c-00474cd3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmMain_defHighscoreGetCaptionRect; original record 00073b5a
 */

/* Named by original Delphi published-method table: TfrmMain_defHighscoreGetCaptionRect; original
   record 00073b5a */

void TfrmMain_defHighscoreGetCaptionRect
               (undefined4 param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00452e7c);
  if ((char)uVar1 == '\0') {
    FUN_00403b34("Assertion failure");
  }
  iVar2 = FUN_0040303c(param_2,(int)&PTR_FUN_00452e7c);
  FUN_0040ebe8(0,*(int *)(iVar2 + 0x48) + -0x24,*(undefined4 *)(iVar2 + 0x44),param_4,
               *(int *)(iVar2 + 0x48));
  return;
}

