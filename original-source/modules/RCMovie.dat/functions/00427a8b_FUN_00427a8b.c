/*
 * FUN_00427a8b at 00427a8b
 * uint * __cdecl FUN_00427a8b(uint * param_1)
 * Address ranges: 00427a8b-00427ab5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint * __cdecl FUN_00427a8b(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  
  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_0041f7a0(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}

