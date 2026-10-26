/*
 * FUN_0046d290 at 0046d290
 * undefined FUN_0046d290(void)
 * Address ranges: 0046d290-0046d313
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d290(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = *(float *)(param_1 + 0x24) / *(float *)(param_1 + 0x28);
  if (0.25 <= fVar2) {
    if (fVar2 < 0.5) {
      FUN_0046d650(0x40000000);
      return;
    }
    fVar1 = 0.0;
    if (0.75 <= fVar2) goto LAB_0046d303;
    fVar2 = 0.75 - fVar2;
  }
  fVar1 = fVar2 * 4.0;
LAB_0046d303:
  FUN_0046d650(fVar1 + 1.0);
  return;
}

