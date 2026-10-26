/*
 * FUN_00435850 at 00435850
 * undefined FUN_00435850(void)
 * Address ranges: 00435850-00435874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00435850(int param_1)

{
  float10 fVar1;
  
  if (DAT_0053bec5 == '\0') {
    fVar1 = (float10)FUN_0048f4d0();
    *(float *)(param_1 + 0xf8) = (float)fVar1;
    DAT_0053bec5 = '\x01';
  }
  return;
}

