/*
 * FUN_00462920 at 00462920
 * undefined FUN_00462920(void)
 * Address ranges: 00462920-0046295b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00462920(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  *param_1 = &PTR_FUN_004d2b88;
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

