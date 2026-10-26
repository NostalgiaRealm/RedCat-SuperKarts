/*
 * FUN_0040e4b0 at 0040e4b0
 * undefined FUN_0040e4b0(void)
 * Address ranges: 0040e4b0-0040e651
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040e4b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = param_1 * 0x11c;
  fVar4 = (float10)FUN_0048f4d0();
  if (fVar4 - (float10)*(float *)(&DAT_00503ff4 + iVar3) < (float10)3.0) {
    cVar1 = FUN_00417e90(param_1);
    uVar2 = DAT_0053be28;
    if (cVar1 == '\0') {
      uVar2 = (&DAT_005081bc)[param_1 * 0x1c];
    }
    FUN_0048da90(uVar2);
    FUN_0048dc30(uVar2);
    (&DAT_00503ef4)[param_1 * 0x47] = 0;
    *(undefined4 *)(&DAT_00503f28 + iVar3) = 0;
    *(undefined4 *)(&DAT_00503f0c + iVar3) = 0;
    *(undefined4 *)(&DAT_00503f08 + iVar3) = 0;
    FUN_0040d230(param_1);
  }
  if (*(float *)(&DAT_00503f08 + iVar3) < 1.5) {
    fVar4 = (float10)FUN_0048f4e0();
    *(float *)(&DAT_00503f0c + iVar3) = (float)(fVar4 + (float10)*(float *)(&DAT_00503f0c + iVar3));
    FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
    FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
    FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
    if (1.5 < *(float *)(&DAT_00503f0c + iVar3)) {
      if ((&DAT_00503f8c)[iVar3] == '\0') {
        (&DAT_00503ef4)[param_1 * 0x47] = 0;
      }
      else {
        (&DAT_00503ef4)[param_1 * 0x47] = 0x1b;
      }
      *(undefined4 *)(&DAT_00503f28 + iVar3) = 0;
      *(undefined4 *)(&DAT_00503f0c + iVar3) = 0;
      *(undefined4 *)(&DAT_00503f08 + iVar3) = 0;
      fVar4 = (float10)FUN_0048f4d0();
      *(float *)(&DAT_00503ff4 + iVar3) = (float)fVar4;
      FUN_0040d230(param_1);
    }
    return;
  }
  *(undefined4 *)(&DAT_00503f28 + iVar3) = 0xc2c80000;
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0xc1700000;
  *(undefined4 *)(&DAT_00503f08 + iVar3) = 0;
  *(undefined4 *)(&DAT_00503f0c + iVar3) = 0;
  if (*(int *)(&DAT_00503fc4 + iVar3) != 0) {
    *(int *)(&DAT_00503fc4 + iVar3) = *(int *)(&DAT_00503fc4 + iVar3) + -1;
  }
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return;
}

