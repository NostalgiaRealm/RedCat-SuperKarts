/*
 * FUN_00410650 at 00410650
 * undefined FUN_00410650(void)
 * Address ranges: 00410650-004106af
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00410650(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  float10 fVar7;
  
  cVar3 = FUN_00417e90(param_1);
  if (cVar3 == '\0') {
    fVar7 = (float10)FUN_0048f4d0();
    fVar6 = (float10)*(float *)(&DAT_00503ff0 + param_1 * 0x11c);
    uVar5 = CONCAT31((int3)(CONCAT22((short)((uint)(param_1 * 0x47) >> 0x10),
                                     (ushort)(fVar7 < fVar6) << 8 |
                                     (ushort)(NAN(fVar7) || NAN(fVar6)) << 10 |
                                     (ushort)(fVar7 == fVar6) << 0xe) >> 8),1);
    if ((uVar5 & 0x4100) == 0) {
      return uVar5;
    }
  }
  else {
    fVar6 = (float10)FUN_0048f4d0();
    fVar1 = (float)fVar6;
    iVar4 = FUN_00435a30();
    fVar2 = *(float *)(iVar4 + 0x100);
    uVar5 = CONCAT22((short)((uint)iVar4 >> 0x10),
                     (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                     (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 < fVar2 == 0 && (fVar1 == fVar2) == 0) {
      return CONCAT31((int3)(uVar5 >> 8),1);
    }
  }
  return uVar5 & 0xffffff00;
}

