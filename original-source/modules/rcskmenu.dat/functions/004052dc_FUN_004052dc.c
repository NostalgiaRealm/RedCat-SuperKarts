/*
 * FUN_004052dc at 004052dc
 * undefined __register FUN_004052dc(undefined4 param_1)
 * Address ranges: 004052dc-004052fa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004052dc(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00402714(8);
  *puVar1 = DAT_0047b020;
  puVar1[1] = param_1;
  DAT_0047b020 = puVar1;
  return;
}

