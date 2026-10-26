/*
 * FUN_0042a2f0 at 0042a2f0
 * undefined FUN_0042a2f0(void)
 * Address ranges: 0042a2f0-0042a341
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a2f0(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) != 0) {
    iVar1 = FUN_0042a1e0(param_1);
    if (*(int *)(&DAT_0053a280 + iVar1 * 0x14) == 0) {
      DVar2 = GetTickCount();
      iVar1 = FUN_0042a1e0(param_1);
      *(DWORD *)(&DAT_0053a280 + iVar1 * 0x14) = DVar2;
    }
  }
  return;
}

