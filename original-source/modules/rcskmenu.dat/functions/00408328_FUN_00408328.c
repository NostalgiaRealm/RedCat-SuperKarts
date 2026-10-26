/*
 * FUN_00408328 at 00408328
 * bool __register FUN_00408328(undefined * param_1)
 * Address ranges: 00408328-0040833f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00408328(undefined *param_1)

{
  LPCSTR lpPathName;
  BOOL BVar1;
  
  lpPathName = FUN_00403f94(param_1);
  BVar1 = SetCurrentDirectoryA(lpPathName);
  return BVar1 != 0;
}

