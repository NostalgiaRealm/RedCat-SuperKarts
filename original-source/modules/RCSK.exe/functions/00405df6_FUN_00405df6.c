/*
 * FUN_00405df6 at 00405df6
 * char * __cdecl FUN_00405df6(int param_1, LPCSTR param_2, undefined4 * param_3, char * param_4)
 * Address ranges: 00405df6-00405e46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * __cdecl FUN_00405df6(int param_1,LPCSTR param_2,undefined4 *param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_0040613d(param_3,(undefined4 *)param_4,&param_4,&param_3);
  if (iVar1 == -1) {
    return (char *)0xffffffff;
  }
  pcVar2 = FUN_00405f5e(param_1,param_2,param_4,param_3);
  FUN_00401779(param_4);
  FUN_00401779(param_3);
  return pcVar2;
}

