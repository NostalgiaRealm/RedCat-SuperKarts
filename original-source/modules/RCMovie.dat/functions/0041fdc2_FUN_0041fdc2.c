/*
 * FUN_0041fdc2 at 0041fdc2
 * undefined __cdecl FUN_0041fdc2(int * param_1)
 * Address ranges: 0041fdc2-0041fe15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041fdc2(int *param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = param_1[4];
  FUN_0042056d(param_1);
  param_1[3] = param_1[3] & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &DAT_004371b8;
  }
  else {
    puVar2 = (undefined *)((&DAT_0043f820)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  if ((param_1[3] & 0x80U) != 0) {
    param_1[3] = param_1[3] & 0xfffffffc;
  }
  FUN_00422935(uVar1,0,0);
  return;
}

