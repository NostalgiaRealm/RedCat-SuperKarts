/*
 * FUN_0041fe68 at 0041fe68
 * uint __cdecl FUN_0041fe68(undefined4 * param_1)
 * Address ranges: 0041fe68-0041fe81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_0041fe68(undefined4 *param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    bVar2 = *(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
    return (uint)bVar2;
  }
  uVar3 = FUN_0042063f(param_1);
  return uVar3;
}

