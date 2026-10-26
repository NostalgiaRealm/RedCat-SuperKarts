/*
 * FUN_00406880 at 00406880
 * undefined FUN_00406880(void)
 * Address ranges: 00406880-0040693b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406880(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_0053b9c0 == 3) || (DAT_0053b9c0 == 6)) {
    FUN_00412c50((&DAT_00503ef0)[param_1 * 0x47],0);
  }
  iVar1 = 2;
  iVar2 = *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) * 0x984 + 0xec;
  do {
    FUN_004067a0(param_1,*(undefined4 *)(iVar2 + DAT_00680b28));
    iVar2 = iVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004067a0(param_1,*(undefined4 *)
                        (*(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x24 + DAT_0067ee20) *
                         0x50 + 4 + DAT_00680ae0));
  return;
}

