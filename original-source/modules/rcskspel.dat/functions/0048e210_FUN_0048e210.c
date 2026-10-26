/*
 * FUN_0048e210 at 0048e210
 * undefined FUN_0048e210(void)
 * Address ranges: 0048e210-0048e256
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0048e210(void)

{
  void *pvVar1;
  
  if (DAT_0067e4d8 == 0) {
    pvVar1 = operator_new(0x388);
    if (pvVar1 != (void *)0x0) {
      DAT_0067e4d8 = FUN_0048e200();
      FUN_0048e480();
      return DAT_0067e4d8;
    }
    DAT_0067e4d8 = 0;
    FUN_0048e480();
  }
  return DAT_0067e4d8;
}

