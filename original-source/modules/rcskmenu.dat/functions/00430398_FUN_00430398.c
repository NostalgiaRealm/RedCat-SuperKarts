/*
 * FUN_00430398 at 00430398
 * undefined __register FUN_00430398(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00430398-004303bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430398(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00402714(0xc);
  *puVar1 = *(undefined4 *)(param_1 + 0x50);
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  *(undefined4 **)(param_1 + 0x50) = puVar1;
  return;
}

