/*
 * FUN_0041f070 at 0041f070
 * undefined __fastcall FUN_0041f070(int param_1)
 * Address ranges: 0041f070-0041f08d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0041f070(int param_1)

{
  int iVar1;
  void *this;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&stack0x00000004;
  iVar1 = FUN_0041f140(param_1 + 0x36);
  this = (void *)FUN_0041e8d0(iVar1);
  FUN_0041e8b0(this,puVar2);
  return;
}

