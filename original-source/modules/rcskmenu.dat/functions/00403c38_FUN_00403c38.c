/*
 * FUN_00403c38 at 00403c38
 * undefined __register FUN_00403c38(int * param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 00403c38-00403c65
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403c38(int *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00403c14(param_3);
  if (param_2 != (undefined4 *)0x0) {
    FUN_0040282c(param_2,puVar1,param_3);
  }
  FUN_00403b50(param_1);
  *param_1 = (int)puVar1;
  return;
}

