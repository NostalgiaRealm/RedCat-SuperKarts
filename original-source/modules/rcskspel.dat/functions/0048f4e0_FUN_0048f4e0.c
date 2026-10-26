/*
 * FUN_0048f4e0 at 0048f4e0
 * undefined FUN_0048f4e0(void)
 * Address ranges: 0048f4e0-0048f511
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 __fastcall FUN_0048f4e0(int param_1)

{
  if (*(float *)(param_1 + 0xc) == 0.0) {
    return (float10)0.1;
  }
  if (0.1 < *(float *)(param_1 + 0xc)) {
    return (float10)0.1;
  }
  return (float10)*(float *)(param_1 + 0xc);
}

