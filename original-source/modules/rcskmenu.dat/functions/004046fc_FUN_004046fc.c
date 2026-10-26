/*
 * FUN_004046fc at 004046fc
 * undefined4 * __register FUN_004046fc(int param_1, char * param_2)
 * Address ranges: 004046fc-0040470e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004046fc(int param_1,char *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00402714(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004043c0(puVar1,param_2);
  }
  return puVar1;
}

