/*
 * FUN_004914d0 at 004914d0
 * undefined FUN_004914d0(void)
 * Address ranges: 004914d0-00491526
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_004914d0(int param_1,float param_2,float param_3,float param_4,float param_5,undefined4 param_6,
            float param_7)

{
  *(float *)(param_1 + 0xb4) = param_2 + *(float *)(param_1 + 0xb4);
  *(float *)(param_1 + 0xb8) = param_3 + *(float *)(param_1 + 0xb8);
  *(float *)(param_1 + 0xbc) = param_4 + *(float *)(param_1 + 0xbc);
  *(float *)(param_1 + 0xc0) = param_2 * -param_7 + param_5 * param_4 + *(float *)(param_1 + 0xc0);
  return;
}

