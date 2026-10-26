/*
 * FUN_00494b70 at 00494b70
 * undefined FUN_00494b70(void)
 * Address ranges: 00494b70-00494b8b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 __thiscall FUN_00494b70(int param_1,float param_2,float param_3)

{
  return (((float10)*(float *)(param_1 + 0xdc) -
          (float10)param_2 * (float10)*(float *)(param_1 + 0x3c)) -
         (float10)param_3 * (float10)*(float *)(param_1 + 0x44)) /
         (float10)*(float *)(param_1 + 0x40);
}

