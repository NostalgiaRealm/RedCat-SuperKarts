/*
 * FUN_00403088 at 00403088
 * undefined __register FUN_00403088(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00403088-0040309c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403088(int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined1 in_ZF;
  
  FUN_00403058(*param_1);
  if (!(bool)in_ZF) {
                    /* WARNING: Could not recover jumptable at 0x00403095. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  FUN_004029c8();
  return;
}

