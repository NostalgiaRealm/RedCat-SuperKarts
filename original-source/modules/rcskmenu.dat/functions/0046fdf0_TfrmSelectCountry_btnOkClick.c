/*
 * TfrmSelectCountry_btnOkClick at 0046fdf0
 * undefined __register TfrmSelectCountry_btnOkClick(int * param_1, undefined4 param_2)
 * Address ranges: 0046fdf0-0046fede
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmSelectCountry_btnOkClick; original record 0006e813
 */

/* Named by original Delphi published-method table: TfrmSelectCountry_btnOkClick; original record
   0006e813 */

void TfrmSelectCountry_btnOkClick(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar4;
  int *in_FS_OFFSET;
  int iStack_3c;
  int iStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_14;
  int local_10 [2];
  undefined4 *local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_10[1] = 0;
  local_10[0] = 0;
  local_14 = (uint *)0x0;
  puStack_24 = &LAB_0046fedf;
  iStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_28;
  cVar2 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                       CONCAT31((int3)((uint)param_2 >> 8),(char)param_1[0xce]));
  if (cVar2 == '\0') {
    FUN_0046fa7c((int)param_1);
    iVar3 = extraout_ECX;
    uVar4 = extraout_EDX;
    if (*(char *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x18) != '\0') {
      cVar2 = FUN_0045bb50(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
      iVar3 = extraout_ECX_00;
      uVar4 = extraout_EDX_00;
      if (cVar2 == '\0') {
        FUN_0046222c();
        iVar3 = extraout_ECX_01;
        uVar4 = extraout_EDX_01;
      }
    }
    *(undefined1 *)(param_1 + 0xb5) = 4;
    FUN_0042eb18(param_1,uVar4,iVar3);
  }
  else {
    FUN_0045c4c8(0x45,local_10 + 1);
    FUN_0045c4c8(0x46,local_10);
    iStack_3c = local_10[0];
    FUN_00403e90((int *)&local_8,5);
    puVar1 = local_8;
    FUN_0045c4f0(0x18,(int *)&local_14);
    FUN_00460df0(local_14,puVar1,4);
  }
  *in_FS_OFFSET = iStack_3c;
  FUN_00403b74((int *)&local_14,4);
  return;
}

