/*
 * FUN_0040812c at 0040812c
 * bool __register FUN_0040812c(undefined * param_1)
 * Address ranges: 0040812c-00408143
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0040812c(undefined *param_1)

{
  LPCSTR lpFileName;
  BOOL BVar1;
  
  lpFileName = FUN_00403f94(param_1);
  BVar1 = DeleteFileA(lpFileName);
  return BVar1 != 0;
}

