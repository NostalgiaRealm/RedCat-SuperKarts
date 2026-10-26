/*
 * FUN_00441538 at 00441538
 * uint __register FUN_00441538(int * param_1, uint param_2, undefined4 param_3)
 * Address ranges: 00441538-00441576
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00441538(int *param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = FUN_00403088(param_1,param_2,param_3);
  if (cVar1 != '\0') {
    if ((param_2 & 2) == 2) {
      param_2 = param_2 & 0xfffffffd;
    }
    else if ((param_2 & 1) != 1) {
      param_2 = param_2 | 2;
    }
  }
  uVar2 = FUN_00441578((int)param_1);
  return param_2 | uVar2;
}

