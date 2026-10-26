/*
 * FUN_0040eba0 at 0040eba0
 * undefined FUN_0040eba0(void)
 * Address ranges: 0040eba0-0040ebf5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0040eba0(int *param_1)

{
  float10 fVar1;
  undefined2 extraout_var;
  uint uVar2;
  float10 fVar3;
  
  if ((&DAT_00503ef4)[*param_1 * 0x47] == param_1[1]) {
    fVar3 = (float10)FUN_0048f4d0();
    fVar1 = (float10)(float)param_1[2];
    if (fVar3 < fVar1 == 0 && (fVar3 == fVar1) == 0) {
      return CONCAT31((int3)(CONCAT22(extraout_var,
                                      (ushort)(fVar3 < fVar1) << 8 |
                                      (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                                      (ushort)(fVar3 == fVar1) << 0xe) >> 8),1);
    }
  }
  uVar2 = param_1[1];
  if ((&DAT_00503ef4)[*param_1 * 0x47] != uVar2) {
    uVar2 = FUN_0040eb90();
  }
  return uVar2 & 0xffffff00;
}

