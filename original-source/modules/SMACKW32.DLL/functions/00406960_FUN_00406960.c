/*
 * FUN_00406960 at 00406960
 * undefined FUN_00406960(void)
 * Address ranges: 00406960-004069a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00406960(int param_1)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
  (*DAT_00410474)();
  if (*(int *)(param_1 + 0x5c) == 0) {
    return 0;
  }
  DVar1 = timeGetTime();
  uVar3 = DVar1 - *(int *)(param_1 + 0x5c);
  if (uVar3 < *(uint *)(param_1 + 0x60)) {
    iVar2 = (int)(((ulonglong)*(uint *)(param_1 + 100) * (ulonglong)uVar3) /
                 (ulonglong)*(uint *)(param_1 + 0x60));
  }
  else {
    iVar2 = *(int *)(param_1 + 100);
  }
  return iVar2 + *(int *)(param_1 + 0x50);
}

