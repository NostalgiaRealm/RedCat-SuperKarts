/*
 * TfrmOptions_btnOkClick at 0046b400
 * undefined __register TfrmOptions_btnOkClick(int * param_1)
 * Address ranges: 0046b400-0046b485
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmOptions_btnOkClick; original record 0006a0e7
 */

/* Named by original Delphi published-method table: TfrmOptions_btnOkClick; original record 0006a0e7
    */

void TfrmOptions_btnOkClick(int *param_1)

{
  int iVar1;
  undefined *puVar2;
  char cVar3;
  int extraout_ECX;
  
  puVar2 = PTR_DAT_0047c670;
  FUN_0045bb54(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),(char)param_1[0xd9]);
  FUN_0045bb64(*(int *)(*(int *)puVar2 + 0x7c),*(undefined1 *)((int)param_1 + 0x365));
  FUN_0045bb5c(*(int *)(*(int *)puVar2 + 0x7c),*(undefined1 *)((int)param_1 + 0x366));
  FUN_0045bb8c(*(int *)(*(int *)puVar2 + 0x7c),param_1[0xda]);
  FUN_0045bb6c(*(int *)(*(int *)puVar2 + 0x7c),param_1[0xdb]);
  cVar3 = (**(code **)(*(int *)param_1[0xd6] + 0xb4))();
  iVar1 = *(int *)(*(int *)puVar2 + 0x7c);
  *(bool *)(iVar1 + 0x18) = cVar3 == '\x01';
  *(undefined1 *)(param_1 + 0xb5) = 1;
  FUN_0042eb18(param_1,iVar1,extraout_ECX);
  return;
}

