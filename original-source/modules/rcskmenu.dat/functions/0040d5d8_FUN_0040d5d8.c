/*
 * FUN_0040d5d8 at 0040d5d8
 * undefined __register FUN_0040d5d8(int * param_1, undefined4 * param_2, LPCSTR param_3)
 * Address ranges: 0040d5d8-0040d603
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d5d8(int *param_1,undefined4 *param_2,LPCSTR param_3)

{
  char cVar1;
  
  cVar1 = **(char **)*param_2;
  if (cVar1 == '\x05') {
    FUN_0040d4a4(param_1,param_2,(undefined4 *)param_3);
    return;
  }
  if (cVar1 == '\n') {
    FUN_0040d4ec(param_1,(int)param_2,(undefined4 *)param_3);
    return;
  }
  if (cVar1 == '\v') {
    FUN_0040d580(param_1,(int)param_2,param_3);
  }
  return;
}

