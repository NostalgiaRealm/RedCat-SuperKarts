/*
 * FUN_00488850 at 00488850
 * undefined FUN_00488850(void)
 * Address ranges: 00488850-004888a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00488850(int param_1)

{
  undefined4 local_4;
  
  if (*(char *)(param_1 + 0x13c) != '\0') {
    if (*(int *)(param_1 + 0x138) == DAT_0053be28) {
      local_4 = DAT_0053bd74 * 0.2;
    }
    else {
      local_4 = 5.0;
    }
    FUN_004885c0(local_4);
    FUN_004884d0();
    FUN_00488440();
  }
  return;
}

