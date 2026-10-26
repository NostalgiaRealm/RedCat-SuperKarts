/*
 * FUN_00401d20 at 00401d20
 * undefined FUN_00401d20(void)
 * Address ranges: 00401d20-00401db7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401d20(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x11c;
  cVar1 = FUN_00415be0(*(undefined4 *)(&DAT_00503ef8 + iVar3));
  if (cVar1 != '\0') {
    uVar2 = FUN_00493a40(*(undefined4 *)
                          ((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20),
                         *(undefined4 *)
                          (*(int *)(&DAT_00503ef8 + iVar3) * 0xd0 + 0x1c + DAT_0067ee20));
    if (((int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) < 2) &&
       (0.0 < *(float *)(*(int *)(&DAT_00503ef8 + iVar3) * 0xd0 + 0xa4 + DAT_0067ee20))) {
      return 1;
    }
  }
  return 0;
}

