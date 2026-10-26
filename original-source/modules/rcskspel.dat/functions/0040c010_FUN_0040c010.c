/*
 * FUN_0040c010 at 0040c010
 * undefined FUN_0040c010(void)
 * Address ranges: 0040c010-0040c089
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined2 FUN_0040c010(int param_1)

{
  char cVar1;
  int iVar2;
  float10 extraout_ST0;
  
  param_1 = param_1 * 0x11c;
  cVar1 = FUN_0040eba0();
  if (cVar1 != '\0') {
    iVar2 = FUN_00410180();
    if ((float)(iVar2 / 1000) <= *(float *)(&DAT_00503f04 + param_1)) {
      return 0;
    }
    FUN_0048f4e0();
    *(float *)(&DAT_00503f04 + param_1) =
         (float)(extraout_ST0 + (float10)*(float *)(&DAT_00503f04 + param_1));
  }
  return 1;
}

