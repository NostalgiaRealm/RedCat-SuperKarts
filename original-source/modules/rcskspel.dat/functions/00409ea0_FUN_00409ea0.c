/*
 * FUN_00409ea0 at 00409ea0
 * undefined FUN_00409ea0(void)
 * Address ranges: 00409ea0-00409f2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409ea0(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = param_1 * 0x11c;
  *(undefined4 *)(&DAT_00503f34 + iVar1) = 1;
  fVar2 = (float10)FUN_0048f4e0();
  fVar2 = fVar2 * (float10)75.0 + (float10)*(float *)(&DAT_00503f28 + iVar1);
  *(float *)(&DAT_00503f28 + iVar1) = (float)fVar2;
  if ((float10)100.0 < fVar2) {
    *(undefined4 *)(&DAT_00503f28 + iVar1) = 0x42c80000;
  }
  *(undefined4 *)(&DAT_00503f2c + iVar1) = 0;
  *(undefined4 *)(&DAT_00503f30 + iVar1) = 0;
  FUN_00414750(param_1);
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return;
}

