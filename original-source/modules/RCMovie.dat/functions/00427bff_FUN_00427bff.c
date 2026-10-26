/*
 * FUN_00427bff at 00427bff
 * char * __cdecl FUN_00427bff(uint param_1, char * param_2, uint param_3)
 * Address ranges: 00427bff-00427c2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * __cdecl FUN_00427bff(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  
  if ((param_3 == 10) && ((int)param_1 < 0)) {
    iVar1 = 1;
    param_3 = 10;
  }
  else {
    iVar1 = 0;
  }
  FUN_00427c2c(param_1,param_2,param_3,iVar1);
  return param_2;
}

