/*
 * FUN_004cb556 at 004cb556
 * undefined FUN_004cb556(void)
 * Address ranges: 004cb556-004cb580
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004cb556(char *param_1)

{
  size_t sVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (param_1 != (char *)0x0) {
    sVar1 = _strlen(param_1);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_004c51f0(pvVar2,param_1);
      return uVar3;
    }
  }
  return 0;
}

