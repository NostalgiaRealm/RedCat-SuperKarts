/*
 * FUN_00430eb8 at 00430eb8
 * undefined __register FUN_00430eb8(char param_1)
 * Address ranges: 00430eb8-00430edc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430eb8(char param_1)

{
  undefined4 local_8;
  int local_4;
  
  local_8 = 8;
  local_4 = -(uint)(param_1 != '\0');
  SystemParametersInfoA(0x49,8,&local_8,0);
  return;
}

