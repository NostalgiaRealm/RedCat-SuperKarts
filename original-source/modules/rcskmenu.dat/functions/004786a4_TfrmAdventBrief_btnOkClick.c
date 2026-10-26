/*
 * TfrmAdventBrief_btnOkClick at 004786a4
 * undefined TfrmAdventBrief_btnOkClick(void)
 * Address ranges: 004786a4-004786eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmAdventBrief_btnOkClick; original record 000776cf
 */

/* Named by original Delphi published-method table: TfrmAdventBrief_btnOkClick; original record
   000776cf */

void TfrmAdventBrief_btnOkClick(int *param_1)

{
  char cVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  
  FUN_0045c7c0();
  FUN_004786ec((int)param_1);
  iVar2 = extraout_ECX;
  uVar3 = extraout_EDX;
  if (*(char *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x18) != '\0') {
    cVar1 = FUN_0045bb50(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
    iVar2 = extraout_ECX_00;
    uVar3 = extraout_EDX_00;
    if (cVar1 == '\0') {
      FUN_0046222c();
      iVar2 = extraout_ECX_01;
      uVar3 = extraout_EDX_01;
    }
  }
  *(undefined1 *)(param_1 + 0xb5) = 4;
  FUN_0042eb18(param_1,uVar3,iVar2);
  return;
}

