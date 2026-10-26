/*
 * FUN_0040b9e0 at 0040b9e0
 * undefined FUN_0040b9e0(void)
 * Address ranges: 0040b9e0-0040ba99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0040b9e0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = param_1 * 0x11c;
  if (0.0 < *(float *)(&DAT_00503f88 + iVar2)) {
    uVar1 = 1;
    *(undefined4 *)(&DAT_00503f34 + iVar2) = 1;
    fVar3 = (float10)FUN_0048f4e0();
    fVar3 = fVar3 * (float10)400.0 + (float10)*(float *)(&DAT_00503f30 + iVar2);
    *(float *)(&DAT_00503f30 + iVar2) = (float)fVar3;
    if ((float10)100.0 < fVar3) {
      *(undefined4 *)(&DAT_00503f30 + iVar2) = 0x42c80000;
    }
    *(undefined4 *)(&DAT_00503f2c + iVar2) = 0;
    fVar3 = (float10)FUN_0048f4e0();
    *(float *)(&DAT_00503f88 + iVar2) = (float)((float10)*(float *)(&DAT_00503f88 + iVar2) - fVar3);
  }
  else {
    uVar1 = 0;
  }
  FUN_00414750(param_1);
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return uVar1;
}

