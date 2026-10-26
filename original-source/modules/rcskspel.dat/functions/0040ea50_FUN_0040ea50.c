/*
 * FUN_0040ea50 at 0040ea50
 * undefined FUN_0040ea50(void)
 * Address ranges: 0040ea50-0040ead8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0040ea50(int param_1)

{
  float10 fVar1;
  undefined2 extraout_var;
  undefined1 *puVar2;
  float10 fVar3;
  
  if ((param_1 < DAT_00508610) && (-1 < param_1)) {
    puVar2 = (undefined1 *)
             CONCAT31((int3)((uint)(param_1 * 0x70) >> 8),(&DAT_00508215)[param_1 * 0x70]);
  }
  else {
    puVar2 = (undefined1 *)CONCAT31((int3)((uint)DAT_00508610 >> 8),DAT_0053bec5);
  }
  if ((char)puVar2 != '\0') {
    fVar3 = (float10)FUN_0048f4d0();
    fVar3 = fVar3 - (float10)*(float *)(&DAT_00503fe8 + param_1 * 0x11c);
    fVar1 = (float10)1.0;
    if (fVar3 < fVar1 != 0) {
      return CONCAT31((int3)(CONCAT22(extraout_var,
                                      (ushort)(fVar3 < fVar1) << 8 |
                                      (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                                      (ushort)(fVar3 == fVar1) << 0xe) >> 8),1);
    }
    if ((param_1 < DAT_00508610) && (-1 < param_1)) {
      (&DAT_00508215)[param_1 * 0x70] = 0;
      return (uint)(&DAT_00508215 + param_1 * 0x70) & 0xffffff00;
    }
    puVar2 = &DAT_0053bec5;
    DAT_0053bec5 = 0;
  }
  return (uint)puVar2 & 0xffffff00;
}

