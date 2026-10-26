/*
 * FUN_0042a420 at 0042a420
 * undefined FUN_0042a420(void)
 * Address ranges: 0042a420-0042a4cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042a420(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  
  iVar1 = FUN_0042a1e0(param_1);
  if (*(int *)(&DAT_0053a27c + iVar1 * 0x14) != 0) {
    iVar1 = FUN_0042a1e0(param_1);
    if (*(int *)(&DAT_0053a280 + iVar1 * 0x14) != 0) {
      iVar1 = FUN_0042a1e0(param_1);
      if (*(int *)(&DAT_0053a274 + iVar1 * 0x14) == -1) {
        iVar1 = FUN_0042a1e0(param_1);
        *(undefined4 *)(&DAT_0053a280 + iVar1 * 0x14) = 0;
        return;
      }
      iVar1 = FUN_0042a1e0(param_1);
      DVar2 = GetTickCount();
      iVar1 = *(int *)(&DAT_0053a280 + iVar1 * 0x14);
      iVar3 = FUN_0042a1e0(param_1);
      *(DWORD *)(&DAT_0053a274 + iVar3 * 0x14) =
           *(int *)(&DAT_0053a274 + iVar3 * 0x14) + (DVar2 - iVar1);
      iVar1 = FUN_0042a1e0(param_1);
      *(undefined4 *)(&DAT_0053a280 + iVar1 * 0x14) = 0;
    }
  }
  return;
}

