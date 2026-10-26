/*
 * FUN_00435880 at 00435880
 * undefined FUN_00435880(void)
 * Address ranges: 00435880-004358b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

ushort __fastcall FUN_00435880(int param_1)

{
  float10 fVar1;
  undefined2 in_AX;
  ushort uVar2;
  float10 fVar3;
  
  uVar2 = CONCAT11((char)((ushort)in_AX >> 8),DAT_0053bec5);
  if (DAT_0053bec5 != '\0') {
    fVar3 = (float10)FUN_0048f4d0();
    fVar3 = fVar3 - (float10)*(float *)(param_1 + 0xf8);
    fVar1 = (float10)1.0;
    uVar2 = (ushort)(fVar3 < fVar1) << 8 | (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
            (ushort)(fVar3 == fVar1) << 0xe;
    if (fVar3 < fVar1) {
      return CONCAT11((char)(uVar2 >> 8),1);
    }
  }
  return uVar2 & 0xff00;
}

