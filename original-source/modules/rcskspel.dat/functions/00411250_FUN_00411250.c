/*
 * FUN_00411250 at 00411250
 * undefined FUN_00411250(void)
 * Address ranges: 00411250-004112c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00411250(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00410d00(param_1);
  if (-1 < iVar1) {
    return -2;
  }
  iVar2 = FUN_00410d30();
  iVar1 = DAT_0067ee20;
  if (-1 < iVar2) {
    (&DAT_00505a30)[iVar2 * 6] = param_1;
    (&DAT_00505a34)[iVar2 * 6] = *(undefined4 *)(param_1 * 0xd0 + 0x1c + iVar1);
    (&DAT_00505a40)[iVar2 * 6] = 1;
    (&DAT_00505a44)[iVar2 * 6] = 1;
    uVar3 = FUN_00494000((&DAT_00505a30)[iVar2 * 6],1);
    (&DAT_00505a38)[iVar2 * 6] = uVar3;
  }
  return iVar2;
}

