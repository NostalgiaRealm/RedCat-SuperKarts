/*
 * FUN_0040ddd0 at 0040ddd0
 * undefined FUN_0040ddd0(void)
 * Address ranges: 0040ddd0-0040de51
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ddd0(int param_1)

{
  int iVar1;
  char cVar2;
  float10 fVar3;
  
  if ((&DAT_00503ef4)[param_1 * 0x47] != 9) {
    cVar2 = DAT_0053bec5;
    if ((param_1 < DAT_00508610) && (-1 < param_1)) {
      cVar2 = (&DAT_00508215)[param_1 * 0x70];
    }
    if (cVar2 == '\0') {
      fVar3 = (float10)FUN_0048f4d0();
      iVar1 = DAT_00508610;
      *(float *)(&DAT_00503fe8 + param_1 * 0x11c) = (float)fVar3;
      if ((param_1 < iVar1) && (-1 < param_1)) {
        (&DAT_00508215)[param_1 * 0x70] = 1;
        return;
      }
      DAT_0053bec5 = '\x01';
    }
  }
  return;
}

