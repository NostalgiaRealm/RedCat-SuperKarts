/*
 * FUN_00481d80 at 00481d80
 * undefined FUN_00481d80(void)
 * Address ranges: 00481d80-00481dc3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00481d80(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_005450a4;
  if (((DAT_005450a4 != 0) && (0.0 <= param_1)) && (param_1 <= 1.0)) {
    uVar2 = __ftol();
    *(undefined4 *)(iVar1 + 0xa0) = uVar2;
  }
  return;
}

