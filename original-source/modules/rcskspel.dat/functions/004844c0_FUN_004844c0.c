/*
 * FUN_004844c0 at 004844c0
 * undefined FUN_004844c0(void)
 * Address ranges: 004844c0-004844dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

ushort __thiscall FUN_004844c0(int param_1,float param_2)

{
  float fVar1;
  ushort uVar2;
  
  param_2 = param_2 + *(float *)(param_1 + 4);
  *(float *)(param_1 + 4) = param_2;
  fVar1 = *(float *)(param_1 + 0xc);
  uVar2 = (ushort)(param_2 < fVar1) << 8 | (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
          (ushort)(param_2 == fVar1) << 0xe;
  if (param_2 >= fVar1) {
    return uVar2;
  }
  return CONCAT11((char)(uVar2 >> 8),1);
}

