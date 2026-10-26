/*
 * FUN_004073d0 at 004073d0
 * undefined FUN_004073d0(void)
 * Address ranges: 004073d0-004073f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004073d0(int param_1)

{
  undefined4 uVar1;
  
  if (*(HWAVEOUT *)(param_1 + 0x38) != (HWAVEOUT)0x0) {
    waveOutReset(*(HWAVEOUT *)(param_1 + 0x38));
  }
  *(undefined4 *)(param_1 + 100) = 0;
  uVar1 = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  return;
}

