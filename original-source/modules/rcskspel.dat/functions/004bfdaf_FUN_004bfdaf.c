/*
 * FUN_004bfdaf at 004bfdaf
 * undefined FUN_004bfdaf(void)
 * Address ranges: 004bfdaf-004bfdeb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_004bfdaf(undefined4 *param_1,undefined4 *param_2)

{
  size_t sVar1;
  void *pvVar2;
  
  *param_1 = &PTR_FUN_004d373c;
  sVar1 = _strlen((char *)*param_2);
  pvVar2 = operator_new(sVar1 + 1);
  param_1[1] = pvVar2;
  if (pvVar2 != (void *)0x0) {
    FUN_004c51f0(pvVar2,*param_2);
  }
  param_1[2] = 1;
  return param_1;
}

