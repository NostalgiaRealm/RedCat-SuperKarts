/*
 * FUN_00482510 at 00482510
 * undefined FUN_00482510(void)
 * Address ranges: 00482510-004825c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_00482510(int param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = param_2 + *(float *)(param_1 + 4);
  *(float *)(param_1 + 4) = fVar3;
  fVar2 = *(float *)(param_1 + 0xc);
  if (fVar3 >= fVar2) {
    return (uint)(ushort)((ushort)(fVar3 < fVar2) << 8 | (ushort)(NAN(fVar3) || NAN(fVar2)) << 10 |
                         (ushort)(fVar3 == fVar2) << 0xe);
  }
  pfVar1 = (float *)(param_1 + 0x14);
  *(float *)(param_1 + 0x20) = *pfVar1;
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
  *(float *)(param_1 + 0x38) =
       (*(float *)(param_1 + 0x2c) / *(float *)(param_1 + 0x10)) * param_2 +
       *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x3c) =
       ((*(float *)(param_1 + 0x30) - *(float *)(param_1 + 0x10) * 9.81) /
       *(float *)(param_1 + 0x10)) * param_2 + *(float *)(param_1 + 0x3c);
  *(float *)(param_1 + 0x40) =
       (*(float *)(param_1 + 0x34) / *(float *)(param_1 + 0x10)) * param_2 +
       *(float *)(param_1 + 0x40);
  *pfVar1 = param_2 * *(float *)(param_1 + 0x38) + *pfVar1;
  *(float *)(param_1 + 0x18) = param_2 * *(float *)(param_1 + 0x3c) + *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = param_2 * *(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x1c);
  return CONCAT31((int3)((uint)pfVar1 >> 8),1);
}

