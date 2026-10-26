/*
 * FUN_00418da0 at 00418da0
 * undefined FUN_00418da0(void)
 * Address ranges: 00418da0-00418ddb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00418da0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  *param_1 = &PTR_FUN_004d253c;
  if (iVar1 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_004bc150(iVar1);
  }
  param_1[1] = 0;
  return;
}

