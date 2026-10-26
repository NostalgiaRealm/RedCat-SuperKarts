/*
 * FUN_00403c14 at 00403c14
 * undefined4 * __register FUN_00403c14(int param_1)
 * Address ranges: 00403c14-00403c36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00403c14(int param_1)

{
  undefined4 *puVar1;
  
  if (0 < param_1) {
    puVar1 = (undefined4 *)FUN_00402714(param_1 + 9);
    puVar1[1] = param_1;
    *puVar1 = 1;
    *(undefined1 *)((int)(puVar1 + 2) + param_1) = 0;
    return puVar1 + 2;
  }
  return (undefined4 *)0x0;
}

