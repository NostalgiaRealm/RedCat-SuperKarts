/*
 * FUN_0046d210 at 0046d210
 * undefined FUN_0046d210(void)
 * Address ranges: 0046d210-0046d28b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046d210(int param_1)

{
  float fVar1;
  undefined4 local_4;
  
  fVar1 = *(float *)(param_1 + 0x24) / *(float *)(param_1 + 0x28);
  local_4 = 0.0;
  if (0.25 <= fVar1) {
    if (fVar1 < 0.5) {
      FUN_0046d680(0x3f800000);
      return;
    }
    if (0.75 <= fVar1) goto LAB_0046d27e;
    fVar1 = 0.75 - fVar1;
  }
  local_4 = fVar1 * 4.0;
LAB_0046d27e:
  FUN_0046d680(local_4);
  return;
}

