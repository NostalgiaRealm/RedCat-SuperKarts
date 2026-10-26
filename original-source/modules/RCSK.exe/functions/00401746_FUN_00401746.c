/*
 * FUN_00401746 at 00401746
 * undefined __cdecl FUN_00401746(LPCSTR param_1, char * param_2, uint param_3)
 * Address ranges: 00401746-00401765
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00401746(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00401f9c();
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00401e2c(param_1,param_2,param_3,puVar1);
  return;
}

