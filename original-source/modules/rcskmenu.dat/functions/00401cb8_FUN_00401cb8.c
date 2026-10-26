/*
 * FUN_00401cb8 at 00401cb8
 * undefined __register FUN_00401cb8(uint * param_1, uint param_2)
 * Address ranges: 00401cb8-00401ce7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401cb8(uint *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 - 4) + (int)param_1);
  if (0xf < (int)param_2) {
    *puVar1 = 0x80000007;
    FUN_00401e74(param_1,param_2 - 4);
    return;
  }
  if (3 < (int)param_2) {
    *param_1 = param_2 | 0x80000002;
    *puVar1 = param_2 | 0x80000002;
  }
  return;
}

