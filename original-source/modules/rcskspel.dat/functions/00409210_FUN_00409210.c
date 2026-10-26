/*
 * FUN_00409210 at 00409210
 * undefined FUN_00409210(void)
 * Address ranges: 00409210-004092d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409210(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (&DAT_00505108)[param_1 * 9];
  iVar1 = *(int *)(iVar3 * 0xd0 + 0x24 + DAT_0067ee20);
  iVar2 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + param_1 * 0x24));
  if (*(int *)(&DAT_00505118 + param_1 * 0x24) == *(int *)(&DAT_0053f674 + iVar2 * 0x340)) {
    *(undefined4 *)(iVar3 * 0xd0 + 0xac + DAT_0067ee20) = 0;
    iVar3 = iVar1 * 0x50 + DAT_00680ae0;
    if ((((*(int *)(iVar3 + 0x24) < 2) && (iVar3 = *(int *)(iVar3 + 0x20), iVar3 != -1)) &&
        (iVar3 = iVar3 * 0x50 + DAT_00680ae0, *(int *)(iVar3 + 0x24) < 1)) &&
       ((iVar3 = *(int *)(iVar3 + 0x20), iVar3 != -1 &&
        (*(int *)(iVar3 * 0x50 + 0x24 + DAT_00680ae0) < 1)))) {
      (&DAT_0050510c)[param_1 * 9] = 0;
      *(undefined4 *)((&DAT_00505108)[param_1 * 9] * 0xd0 + 0xa4 + DAT_0067ee20) = 0x41200000;
    }
  }
  return;
}

