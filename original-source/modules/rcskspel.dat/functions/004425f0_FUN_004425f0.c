/*
 * FUN_004425f0 at 004425f0
 * undefined FUN_004425f0(void)
 * Address ranges: 004425f0-00442639
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004425f0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004425a0();
  if (iVar1 != 0) {
    if ((&DAT_0053a6a4)[DAT_0053b9b4 * 0x25] == 0) {
      FUN_00442570(param_1);
    }
    else {
      FUN_004424f0(param_1);
    }
    FUN_00430610(0xb);
    DAT_0053d330 = 1;
  }
  return;
}

