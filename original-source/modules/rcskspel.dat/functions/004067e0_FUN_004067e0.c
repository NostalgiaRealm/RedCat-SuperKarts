/*
 * FUN_004067e0 at 004067e0
 * undefined FUN_004067e0(void)
 * Address ranges: 004067e0-00406876
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004067e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 2;
  iVar2 = *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) * 0x984 + 0xec;
  do {
    if (*(int *)(iVar2 + DAT_00680b28) != 0x35) {
      FUN_00406470(param_1,*(int *)(iVar2 + DAT_00680b28));
    }
    iVar2 = iVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00406470(param_1,*(undefined4 *)
                        (*(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x24 + DAT_0067ee20) *
                         0x50 + 4 + DAT_00680ae0));
  return;
}

