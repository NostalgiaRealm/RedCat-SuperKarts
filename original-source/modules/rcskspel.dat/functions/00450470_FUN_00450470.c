/*
 * FUN_00450470 at 00450470
 * undefined FUN_00450470(void)
 * Address ranges: 00450470-004504ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __thiscall FUN_00450470(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  
  FUN_00450440();
  cVar1 = FUN_00450460(param_1);
  if (cVar1 == '\0') {
    *param_1 = *param_2;
    param_1[5] = param_2[5];
    FUN_0044ff10(param_2[1]);
    FUN_004500e0();
  }
  return param_1;
}

