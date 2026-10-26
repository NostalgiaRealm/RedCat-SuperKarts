/*
 * TfrmDisplaySettings_cboDriverChange at 0046a198
 * undefined TfrmDisplaySettings_cboDriverChange(void)
 * Address ranges: 0046a198-0046a284
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_cboDriverChange; original record 0006911e
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_cboDriverChange; original
   record 0006911e */

void TfrmDisplaySettings_cboDriverChange(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  (**(code **)(**(int **)(*(int *)(param_1 + 0x304) + 0x1f0) + 0x40))();
  FUN_00424744(*(int **)(param_1 + 0x304),0xffffffff);
  iVar2 = FUN_00424728(*(int **)(param_1 + 0x2f8));
  if (-1 < iVar2) {
    FUN_0045bbb0(*(undefined4 *)(*(int *)PTR_DAT_0047c670 + 0x7c),1);
    iVar2 = FUN_00424728(*(int **)(param_1 + 0x2f8));
    if (iVar2 < 2) {
      cVar1 = FUN_004699c4(*(undefined4 *)(*(int *)(param_1 + 0x338) + 0x2c));
      if (cVar1 == '\0') {
        FUN_0046a0ec(2);
        FUN_0046a088(2,extraout_EDX_01,puVar4,(int)&stack0xfffffffc);
      }
      else {
        FUN_0046a0ec(3);
        FUN_0046a088(3,extraout_EDX_00,puVar3,(int)&stack0xfffffffc);
      }
      (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))(*(int **)(param_1 + 0x304),0);
    }
    else {
      FUN_00469fec();
      (**(code **)(**(int **)(param_1 + 0x304) + 0x5c))(*(int **)(param_1 + 0x304),1);
      FUN_0046a088(*(int *)(*(int *)(param_1 + 0x338) + 0x2c),extraout_EDX,extraout_ECX,
                   (int)&stack0xfffffffc);
    }
  }
  return;
}

