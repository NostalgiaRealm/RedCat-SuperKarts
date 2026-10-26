/*
 * FUN_0046d320 at 0046d320
 * undefined FUN_0046d320(void)
 * Address ranges: 0046d320-0046d3b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d320(int param_1)

{
  float fVar1;
  undefined4 local_4;
  
  local_4 = 0.0;
  fVar1 = *(float *)(param_1 + 0x24) / *(float *)(param_1 + 0x28);
  if (0.25 <= fVar1) {
    if (fVar1 < 0.5) {
      local_4 = 1.0;
      goto LAB_0046d385;
    }
    if (0.75 <= fVar1) goto LAB_0046d385;
    fVar1 = 0.75 - fVar1;
  }
  local_4 = fVar1 * 4.0;
LAB_0046d385:
  FUN_0046d650((1.0 - local_4) + (1.0 - local_4) + 1.0);
  FUN_0046d680(local_4);
  return;
}

