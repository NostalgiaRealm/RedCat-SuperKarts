/*
 * FUN_00485450 at 00485450
 * undefined FUN_00485450(void)
 * Address ranges: 00485450-004854b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __fastcall FUN_00485450(int param_1)

{
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x138) == '\0') {
    return false;
  }
  if (*(int *)(param_1 + 0x134) == DAT_0053be28) {
    local_4 = DAT_0053bd74 * 0.2;
  }
  else {
    local_4 = 5.0;
  }
  FUN_004851c0(local_4);
  FUN_00485120(local_4);
  FUN_00485070();
  return *(char *)(param_1 + 0x138) == '\0';
}

