/*
 * FUN_00419758 at 00419758
 * undefined __cdecl FUN_00419758(int * param_1, int * param_2, undefined1 param_3)
 * Address ranges: 00419758-004197d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00419758(int *param_1,int *param_2,undefined1 param_3)

{
  size_t sVar1;
  
  *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = param_3;
  param_1[0xb] = param_1[0xb] + 1;
  sVar1 = _strlen((char *)((int)param_1 + param_1[0xc] * 0x65 + 0x50));
  if (sVar1 < (uint)param_1[0xb]) {
    *(undefined1 *)((int)param_1 + param_1[0xb] + param_1[0xc] * 0x65 + 0x50) = 0;
  }
  FUN_004195c9(param_1,param_2);
  return;
}

