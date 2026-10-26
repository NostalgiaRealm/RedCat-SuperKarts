/*
 * FUN_00422910 at 00422910
 * undefined __cdecl FUN_00422910(char * param_1, int param_2)
 * Address ranges: 00422910-00422934
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00422910(char *param_1,int param_2)

{
  size_t sVar1;
  
  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_00425c30((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}

