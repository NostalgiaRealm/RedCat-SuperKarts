/*
 * FUN_004019f0 at 004019f0
 * undefined FUN_004019f0(void)
 * Address ranges: 004019f0-00401a4e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004019f0(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = param_1 * 0x11c;
  if (*(float *)(&DAT_00503f04 + iVar1) < 4.0) {
    fVar2 = (float10)FUN_0048f4e0();
    *(float *)(&DAT_00503f04 + iVar1) = (float)(fVar2 + (float10)*(float *)(&DAT_00503f04 + iVar1));
    return 0;
  }
  *(undefined4 *)(&DAT_00503f04 + iVar1) = 0;
  FUN_00412c50((&DAT_00503ef0)[param_1 * 0x47],0);
  return 1;
}

