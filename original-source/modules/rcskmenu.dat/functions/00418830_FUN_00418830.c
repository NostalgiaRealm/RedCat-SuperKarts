/*
 * FUN_00418830 at 00418830
 * undefined __register FUN_00418830(int param_1)
 * Address ranges: 00418830-0041887b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418830(int param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_18;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d6b0);
  uStackY_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_18;
  if (*(int *)(param_1 + 0x50) == 0) {
    FUN_004185e8(param_1);
  }
  *in_FS_OFFSET = uStackY_18;
  uStackY_18 = 0x41887b;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d6b0);
  return;
}

