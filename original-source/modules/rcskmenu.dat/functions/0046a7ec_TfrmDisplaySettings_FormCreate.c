/*
 * TfrmDisplaySettings_FormCreate at 0046a7ec
 * undefined TfrmDisplaySettings_FormCreate(void)
 * Address ranges: 0046a7ec-0046a819
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Named by original Delphi published-method table: TfrmDisplaySettings_FormCreate; original record 000691f2
 */

/* Named by original Delphi published-method table: TfrmDisplaySettings_FormCreate; original record
   000691f2 */

void TfrmDisplaySettings_FormCreate(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0045adfc(&PTR_FUN_0045ada4,1);
  *(undefined4 *)(param_1 + 0x338) = uVar1;
  DirectDrawEnumerateA();
  return;
}

