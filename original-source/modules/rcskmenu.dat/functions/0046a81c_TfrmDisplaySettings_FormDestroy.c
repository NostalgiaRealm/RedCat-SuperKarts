/*
 * TfrmDisplaySettings_FormDestroy at 0046a81c
 * undefined TfrmDisplaySettings_FormDestroy(void)
 * Address ranges: 0046a81c-0046a874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_FormDestroy; original record 00069203
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_FormDestroy; original record
   00069203 */

void TfrmDisplaySettings_FormDestroy(int param_1)

{
  int *piVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x2f8) + 0x1f0) + 0x14))();
    if (iVar2 < 3) break;
    piVar1 = *(int **)(*(int *)(param_1 + 0x2f8) + 0x1f0);
    iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,2);
    FUN_0040272c(iVar2);
    piVar1 = *(int **)(*(int *)(param_1 + 0x2f8) + 0x1f0);
    (**(code **)(*piVar1 + 0x44))(piVar1,2);
  }
  FUN_00402eac(*(int **)(param_1 + 0x338));
  return;
}

