/*
 * FUN_00401cd1 at 00401cd1
 * undefined4 __cdecl FUN_00401cd1(uint * param_1)
 * Address ranges: 00401cd1-00401ce8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00401cd1(uint *param_1)

{
  uint *puVar1;
  
  puVar1 = FUN_0041f7a0((uint *)&DAT_004383e0,param_1);
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}

