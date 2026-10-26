/*
 * FUN_0040baa0 at 0040baa0
 * undefined FUN_0040baa0(void)
 * Address ranges: 0040baa0-0040bbc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040baa0(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar3 = param_1 * 0x11c;
  if (0.0 <= *(float *)(&DAT_00503f88 + iVar3)) {
    iVar4 = (&DAT_00503ef0)[param_1 * 0x47];
    fVar5 = (float10)FUN_0048f4e0();
    iVar2 = DAT_0067ee20;
    iVar4 = iVar4 * 0xd0;
    *(float *)(&DAT_00503f88 + iVar3) = (float)((float10)*(float *)(&DAT_00503f88 + iVar3) - fVar5);
    pfVar1 = (float *)(iVar4 + 0xa4 + iVar2);
    if (10.0 < *(float *)(iVar4 + 0xa4 + iVar2)) {
      fVar5 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)((float10)*pfVar1 -
                       fVar5 * (float10)*(float *)(iVar4 + 0xa4 + DAT_0067ee20) * (float10)1.5);
      if (*(float *)(iVar4 + 0xa4 + DAT_0067ee20) < 10.0) {
        *(undefined4 *)(iVar4 + 0xa4 + DAT_0067ee20) = 0x41200000;
      }
    }
    FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
    FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
    FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
    return 1;
  }
  *(undefined4 *)(&DAT_00503f34 + iVar3) = 0;
  *(undefined4 *)(&DAT_00503f28 + iVar3) = 0;
  *(undefined4 *)(&DAT_00503f30 + iVar3) = 0;
  FUN_00414750(param_1);
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return 0;
}

