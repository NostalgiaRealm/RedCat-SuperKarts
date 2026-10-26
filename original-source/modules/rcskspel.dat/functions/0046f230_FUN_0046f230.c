/*
 * FUN_0046f230 at 0046f230
 * undefined FUN_0046f230(void)
 * Address ranges: 0046f230-0046f24f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046f230(int param_1)

{
  undefined4 uVar1;
  
  if (0 < DAT_0053ba18) {
    FUN_0048f4d0();
    uVar1 = __ftol();
    *(undefined4 *)(param_1 + 0xc) = uVar1;
  }
  return;
}

