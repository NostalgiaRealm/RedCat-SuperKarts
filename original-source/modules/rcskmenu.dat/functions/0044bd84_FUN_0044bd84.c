/*
 * FUN_0044bd84 at 0044bd84
 * undefined4 __register FUN_0044bd84(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0044bd84-0044bdae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044bd84(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined3 extraout_var;
  
  if (((char)param_1[0x7e] == '\0') &&
     (cVar1 = FUN_00446278(param_1,param_2,param_3), cVar1 != '\0')) {
    return CONCAT31(extraout_var,1);
  }
  return 0;
}

