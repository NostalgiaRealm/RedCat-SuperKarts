/*
 * FUN_00430e88 at 00430e88
 * bool __register FUN_00430e88(void)
 * Address ranges: 00430e88-00430eb5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00430e88(void)

{
  BOOL BVar1;
  undefined4 local_8;
  int local_4;
  
  local_8 = 8;
  BVar1 = SystemParametersInfoA(0x48,8,&local_8,0);
  if (BVar1 != 0) {
    return local_4 != 0;
  }
  return false;
}

