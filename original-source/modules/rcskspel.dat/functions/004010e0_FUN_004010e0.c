/*
 * FUN_004010e0 at 004010e0
 * undefined FUN_004010e0(void)
 * Address ranges: 004010e0-004011ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004010e0(int param_1,undefined4 *param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar4 = param_1 * 0x11c;
  uVar2 = FUN_00414360((&DAT_00503ef0)[param_1 * 0x47],*param_2,param_2[1],param_2[2]);
  iVar3 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
  if (500 < iVar3) {
    iVar3 = 500;
  }
  fVar1 = (float)(0x46 - iVar3 / 0xf);
  if (*(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) < fVar1) {
    fVar5 = (float10)FUN_0048f4e0();
    fVar5 = fVar5 * (float10)75.0 + (float10)*(float *)(&DAT_00503f2c + iVar4);
    *(float *)(&DAT_00503f2c + iVar4) = (float)fVar5;
    if ((float10)100.0 < fVar5) {
      *(undefined4 *)(&DAT_00503f2c + iVar4) = 0x42c80000;
    }
    *(undefined4 *)(&DAT_00503f30 + iVar4) = 0;
    return;
  }
  if (param_1 < DAT_00508610) {
    fVar5 = (float10)FUN_0048f4e0();
    fVar5 = fVar5 * (float10)400.0 + (float10)*(float *)(&DAT_00503f30 + iVar4);
    *(float *)(&DAT_00503f30 + iVar4) = (float)fVar5;
    if ((float10)100.0 < fVar5) {
      *(undefined4 *)(&DAT_00503f30 + iVar4) = 0x42c80000;
      return;
    }
  }
  else {
    *(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = fVar1;
  }
  return;
}

